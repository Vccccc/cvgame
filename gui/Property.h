# pragma once
#include <string>
#include <algorithm>
using namespace std;

class PropertyReceiver
{
public:
    PropertyReceiver(){}
    virtual ~PropertyReceiver(){}
};

class Property
{
public:
    Property(string name, string defaultValue = "", string dataType = "Unknow") 
    :   name_(move(name)), 
        default_(move(defaultValue)), 
        dataType_(move(dataType)) 
    {}

    virtual ~Property() {}

    const string &getName() { return name_; }
    const string &getDataType() { return dataType_; }

    virtual string get(const PropertyReceiver* receiver) const = 0;
    virtual void set(const PropertyReceiver* receiver, const string& val) = 0;
    virtual bool isReadable() const = 0
    {
        return true;
    }
    virtual bool isWritable() const = 0
    {
        return true;
    }

protected:
    string name_;
    string default_;
    string dataType_;
};