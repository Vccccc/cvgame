#pragma once
#include "noncopyable.h"
template<typename T>
class Singleton : public noncopyable
{
public:
    Singleton() {}
    virtual ~Singleton() {}

    static T* Instance()
    {
        return instance_;
    }

    static T* Instance(T* newInstance)
    {
        instance_ = newInstance;
        return instance_;
    }
private:
    static T* instance_;
};
