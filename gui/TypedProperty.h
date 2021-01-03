# pragma once
#include "Property.h"
#include "PropertyHelper.h"
#include "../common/common.h"
template<typename T>
class TypedProperty : public Property
{
public:
    typedef PropertyHelper<T> Helper;
public:
    TypedProperty(string name, string defaultValue = T())
        : Property(name, defaultValue, Helper::getDataTypeName())
        {

        }

    virtual ~TypedProperty() {}

    virtual void set(const PropertyReceiver* receiver, const string& val)
    {
        setNative(receiver, Helper::fromString(val));
    }

    virtual string get(const PropertyReceiver* receiver) const
    {
        return Helper::toString(getNative(receiver));
    }

    virtual typename Helper::return_type getNative(const PropertyReceiver* receiver) const
    {
        if(isReadable())
        {
            return getNative_impl(receiver);
        }
        else
        {
            throw InvalidRequestException(string("Property ") + ":" + name_ + " is not readable!"));
        }
    }

    virtual void setNative(const PropertyReceiver* receiver, typename Helper::pass_type val)
    {
        if(isWritable())
        {
            return setNative_impl(receiver);
        }
        else
        {
            throw InvalidRequestException(string("Property ") + ":" + name_ + " is not writable!"));
        }
    }
private:
    virtual typename Helper::return_type getNative_impl(const PropertyReceiver *receiver) const = 0;
    virtual void setNative_impl(const PropertyReceiver *receiver, typename Helper::pass_type val) = 0;
    
};