#include "skillFactory.h"

SkillFactory::SkillFactoryPtr SkillFactory::instance()
{
    if(instance_ == nullptr)
    {
        instance_.reset(new SkillFactory);
    }
    return instance_;
}

