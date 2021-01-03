# pragma once
#include <cstdio>
#include <string>
using std::snprintf;
using std::sscanf;
using std::string;

template <typename T>
class PropertyHelper;

template <typename T>
class PropertyHelper<const T>
{
public:
    typedef typename PropertyHelper<T>::return_type return_type;
    typedef typename PropertyHelper<T>::pass_type pass_type;

    static const string& getDataTypeName()
    {
        return PropertyHelper<T>::getDataTypeName();
    }

    static inline return_type fromString(const string& str)
    {
        return PropertyHelper<T>::fromString(str);
    }

    static inline string toString(pass_type val)
    {
        return PropertyHelper<T>::toString(val);
    }

};

template <typename T>
class PropertyHelper<const T&>
{
public:
    typedef typename PropertyHelper<T>::return_type return_type;
    typedef typename PropertyHelper<T>::pass_type pass_type;

    static const string& getDataTypeName()
    {
        return PropertyHelper<T>::getDataTypeName();
    }

    static inline return_type fromString(const string& str)
    {
        return PropertyHelper<T>::fromString(str);
    }

    static inline string toString(pass_type val)
    {
        return PropertyHelper<T>::toString(val);
    }
};

template <typename T>
class PropertyHelper<const T*>
{
public:
    typedef typename PropertyHelper<T>::return_type return_type;
    typedef typename PropertyHelper<T>::pass_type pass_type;

    static const string& getDataTypeName()
    {
        return PropertyHelper<T>::getDataTypeName();
    }

    static inline return_type fromString(const string& str)
    {
        return PropertyHelper<T>::fromString(str);
    }

    static inline string toString(pass_type val)
    {
        return PropertyHelper<T>::toString(val);
    }
};

template<>
class PropertyHelper<bool>
{
public:
    typedef bool return_type;
    typedef bool pass_type;

    static const string& getDataTypeName() 
    {
        static string type("bool");
        return type;
    }

    static inline return_type fromString(const string& str)
    {
        return str == True || str == "True";
    }

    static inline string toString(pass_type val)
    {
        return val ? True : False;
    }

    static const string True;
    static const string False;
};
const string PropertyHelper<bool>::True("true");
const string PropertyHelper<bool>::False("false");

template<>
class PropertyHelper<int>
{
public:
    typedef int return_type;
    typedef int pass_type;

    static const string& getDataTypeName()
    {
        static string type("int");
        return type;
    }

    static inline return_type fromString(const string& str)
    {
        int val = 0;
        sscanf(str.c_str(), " %d", &val);
        return val;
    }

    static inline string toString(pass_type val)
    {
        char buff[64];
        snprintf(buff, sizeof(buff), "%d", val);
        return string(buff);
    }
};

template<>
class PropertyHelper<string>
{
public:
    typedef string return_type;
    typedef const string& pass_type;

    static const string& getDataTypeName() 
    {
        static string type("string");
        return type;
    }

    static inline return_type fromString(const string& str)
    {
        return str;
    }

    static inline string toString(pass_type val)
    {
        return val;
    }
};