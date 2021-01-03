#pragma once
<<<<<<< HEAD
#include "noncopyable.h"
=======

#include "common.h"
#include <memory>

>>>>>>> 5590a51084f1a59c08cafbac36b83658f09fe9d6
template<typename T>
class Singleton : public noncopyable
{
public:
<<<<<<< HEAD
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
=======
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
>>>>>>> 5590a51084f1a59c08cafbac36b83658f09fe9d6
