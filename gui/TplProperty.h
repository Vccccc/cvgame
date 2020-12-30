#pragma once
#include "TypedProperty.h"
#include "../common/common.h"


template<typename C, typename T>
class TplProperty : public TypedProperty<T>
{
public:
    typedef PropertyHelper<T> Helper;

    typedef void (C::*Setter)(typename Helper::pass_type);

    struct GetterFunctor
    {
        template<typename DT>
        class EnsurePlain
        {
            typedef DT result;
        };

        template<typename DT>
        class EnsurePlain<DT&>
        {
            typedef DT result;
        };

        template<typename DT>
        class EnsurePlain<const DT&>
        {
            typedef DT result;
        };

        template<typename DT>
        class EnsureConstRef
        {
            typedef const DT& result;
        };

        template<typename DT>
        class EnsureConstRef<DT&>
        {
            typedef const DT& result;
        };

        template<typename DT>
        class EnsureConstRef<const DT&>
        {
            typedef const DT& result;
        };

        template<typename DT>
        class EnsureRef
        {
            typedef DT& result;
        };

        template<typename DT>
        class EnsureRef<DT&>
        {
            typedef DT& result;
        };

        template<typename DT>
        class EnsureRef<const DT&>
        {
            typedef DT& result;
        };

        typedef typename EnsurePlain<typename Helper::return_type>::result (C::*PlainGetter)() const;
        typedef typename EnsureConstRef<typename Helper::return_type>::result (C::*ConstRefGetter)() const;
        typedef typename EnsureRef<typename Helper::return_type>::result (C::*RefGetter)() const;

        GetterFunctor(PlainGetter getter) 
            : plainGetter_(getter), constRefGetter_(0), refGetter_(0)
        {

        }

        GetterFunctor(ConstRefGetter getter) 
            : plainGetter_(0), constRefGetter_(getter), refGetter_(0)
        {
            
        }

        GetterFunctor(RefGetter getter) 
            : plainGetter_(0), constRefGetter_(0), refGetter_(getter)
        {
            
        }

        GetterFunctor(int) 
            : plainGetter_(0), constRefGetter_(0), refGetter_(0)
        {
            
        }

        operator bool() const
        {
            return plainGetter_ || constRefGetter_ || refGetter_;
        }

        typename Helper::return_type operator(const C *instance) const
        {
            if(plainGetter_)
                return CALL_MEMBER_FN(*instance, plainGetter_)();
            if(constRefGetter_)
                return CALL_MEMBER_FN(*instance, constRefGetter_)();
            if(refGetter_)
                return CALL_MEMBER_FN(*instance, refGetter_)();

            return CALL_MEMBER_FN(*instance, plainGetter_)();
        }
        PlainGetter plainGetter_;
        ConstRefGetter constRefGetter_;
        RefGetter refGetter_;
    };
    TplProperty(string name, Setter setter, GetterFunctor getter, string defaultValue = T())
        : TypedProperty(name, defaultValue), setter_(setter), getter_(getter)
        {}

protected:
    Setter setter_;
    GetterFunctor getter_;
};

