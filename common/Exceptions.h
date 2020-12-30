#pragma once
#include "../gui/PropertyHelper.h"
#include <iostream>
#include <string>
#include <exception>
using std::string;

class Exception : public std::exception
{
public:
    //! Virtual destructor.
    virtual ~Exception(void) throw()
    {

    }

    /*!
    \brief
        Return a reference to the string object describing the reason for the
        exception being thrown.

    \return
        string object containing a message describing the reason for the
        exception.
    */
    const string& getMessage(void) const
        { return message_; }

    /*!
    \brief
        Return a reference to the string object containing the exception name
        (i.e. class type).

    \return
        string object containing the exception name.
    */
    const string& getName() const
        { return name_; }

    /*!
    \brief
        Return a reference to the string object containing the name of the file
        where the exception occurred.

    \return
        string object containing the name of the file where the exception
        occurred.
    */
    const string& getFileName(void) const
        { return filename_; }

    /*!
    \brief
        Return the line number where the exception occurred.

    \Return
        Integer representing the line number where the exception occurred.
    */
    int getLine(void) const
        { return line_; }

    /*!
    \brief
        Return a reference to the string object containing the name of the
        function where the exception occurred.

    \return
        string object containing the name of the function where the exception
        occurred.
    */
    const string& getFunctionName(void) const
        { return function_; }

    // override from std::exception.
    const char* what() const throw()
    {
        return what_.c_str();
    }

    /*!
    \brief
    	Sets whether every exception construction should output to stderr

    \note
    	The default is true, all constructed exceptions output to stderr

    	You should only set it to false if you:
    	1) Know where your log is
    	2) Know what the log is for
    	3) Know how to use the info that's in the log
    */
    static void setStdErrEnabled(bool enabled)
    {
        stdErrEnabled_ = enabled;
    }

    /*!
    \brief
    	Checks whether newly constructed exceptions will output to stderr

   	\see
   		Exception::setStdErrEnabled
    */
    static bool isStdErrEnabled()
    {
        return stdErrEnabled_;
    }

protected:
    //! if this is true, newly constructed exceptions will output to stderr
    static bool stdErrEnabled_;

    /*!
    \brief
        Protected constructor that prevents instantiations (users should employ
        derived exception classes instead) and that is responsible for logging
        the exception.

    \param message
        string object describing the reason for the exception being thrown.

    \param name
        string object describing the exception class name
        (e.g. CEGUI::UnknownObjectException)

    \param filename
        string object containing the name of the file where the exception
        occurred.

    \param line
        Integer representing the line number where the exception occurred.

    \param function
        string object containing the name of the function where the exception
        occurred.
    */
    Exception(const string& message = "",
              const string& name = "CEGUI::Exception",
              const string& filename = "",
              int line = 0,
              const string& function = "") :
        message_(message),
        name_(name),
        filename_(filename),
        line_(line),
        function_(function),
        what_(name + " in function '" + function +
            "' (" + filename + ":" + PropertyHelper<int>::toString(line) + ") : " +
            message)
    {
        if (stdErrEnabled_)
        {
            // output to stderr unless it's explicitly disabled
            // nobody seems to look in their log file!
            std::cerr << what() << std::endl;
        }
    }

    //! Holds the reason for the exception being thrown.
    string message_;
    //! Holds the class name of the exception (e.g. CEGUI::ObjectInUseException)
    string name_;
    //! Holds the name of the file where the exception occurred.
    string filename_;
    //! Holds the line number where the exception occurred.
    int line_;
    //! Holds the name of the function where the exception occurred.
    string function_;
    //! Holds the default error message.
    string what_;
};
bool Exception::stdErrEnabled_(true);

class InvalidRequestException : public Exception
{
public:
    InvalidRequestException(const string& message,
                            const string& file = "unknown", int line = 0,
                            const string& function = "unknown") :
        Exception(message, "CEGUI::InvalidRequestException", file, line, function)
    {}
};