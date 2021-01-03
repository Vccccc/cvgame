#pragma once

class noncopyable
{
protected:
    noncopyable() {}
    virtual ~noncopyable() {}
private:
    noncopyable(const noncopyable &) = delete;
    noncopyable& operator=(const noncopyable &) = delete;
};
