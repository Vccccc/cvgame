# pragma once
#include "FreeFunctionSlot.h"

// 通过 SubscriberSlot 的构造函数可以构造不同类型的 SlotFunctorBase 子类
class SubscriberSlot
{
public:
    SubscriberSlot() : functor_impl_(nullptr) {}
    SubscriberSlot(FreeFunctionSlot::SlotFunction* func) :
        functor_impl_(new FreeFunctionSlot(func)){}

    SubscriberSlot(FreeFunctionSlotVoid::SlotFunction* func) :
        functor_impl_(new FreeFunctionSlotVoid(func)){}

    bool operator()(const EventArgs& args) const
    {
        return (*functor_impl_)(args);
    }

    bool connected() const
    {
        return functor_impl_ != 0;
    }

    void cleanup()
    {
        delete functor_impl_;
        functor_impl_ = 0;
    }

private:
    SlotFunctorBase *functor_impl_;
};