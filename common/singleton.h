#pragma once
#include "noncopyable.h"

template<typename T>
class Singleton : public noncopyable
{
public:
    static T* Instance()
    {
        return instance_;
    }


    T* Instance(T* instance = nullptr)
    {
        if(instance)
        {
            if(instance_)
            {
                delete instance_;
            }
            instance_ = instance;
        }
        return instance_;
    }
private:
    Singleton() {}
    ~Singleton() {}
    static T* instance_;
};

template <typename T>
T *Singleton<T>::instance_ = nullptr;
