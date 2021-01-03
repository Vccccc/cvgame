#pragma once
<<<<<<< HEAD

class noncopyable
{
public:
    noncopyable(){}
    ~noncopyable(){}
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};
=======
class noncopyable
{
protected:
    noncopyable() {}
    virtual ~noncopyable() {}
private:
    noncopyable(const noncopyable &) = delete;
    noncopyable& operator=(const noncopyable &) = delete;
};
>>>>>>> 5590a51084f1a59c08cafbac36b83658f09fe9d6
