#pragma once

#include "common.h"
#include <memory>


using std::shared_ptr;

template<typename T>
class Singleton : public noncopyable
{
public:
    shared_ptr<T> Instance()
    {
        if(instance_ == nullptr)
        {
            Create();
        }
        return instance_;
    }

    void Create()
    {
        instance_.reset(new T);
    }
private:
    Singleton() {}
    
    static shared_ptr<T> instance_;
}