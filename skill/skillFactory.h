#pragma once
#include "skillBase.h"
#include "common/common.h"


#include <unordered_map>
#include <memory>

using std::shared_ptr;
using std::unordered_map;

enum ESkillType
{
    ESkillType_Test,
};

class SkillFactory : public Singleton<SkillFactory>
{
public:
    using SkillBasePtr = shared_ptr<SkillBase>;

private:
    SkillFactory() {}
public:
    void registor(const ESkillType &skillType, const SkillBasePtr& skill);
    SkillBasePtr getSkill(const ESkillType &skillType)
    {
        if(skills_.count(skillType))
        {
            return skills_[skillType];
        }
        else
        {
            return nullptr;
        }
    }


private:
    unordered_map<ESkillType, SkillBasePtr> skills_;
};

