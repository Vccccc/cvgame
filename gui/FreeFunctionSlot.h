#include "SlotFunctorBase.h"
class FreeFunctionSlot : public SlotFunctorBase
{
public:
    typedef bool(SlotFunction)(const EventArgs &);

public:
    FreeFunctionSlot(SlotFunction* func) : function_(func){}

    virtual bool operator()(const EventArgs& args)
    {
        return function_(args);
    }
private:
    SlotFunction *function_;
};

class FreeFunctionSlotVoid : public SlotFunctorBase
{
public:
    //! Slot function type.
    typedef void (SlotFunction)(const EventArgs&);

    FreeFunctionSlotVoid(SlotFunction* func) :
        function_(func)
    {}

    virtual bool operator()(const EventArgs& args)
    {
        function_(args);

        return true;
    }

private:
    SlotFunction* function_;
};