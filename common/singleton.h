#pragma once

#include "common.h"
#include <memory>

template<typename T>
class Singleton : public noncopyable
{
public:
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