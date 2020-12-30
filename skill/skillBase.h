#pragma once
#include "common/common.h"
#include "playerEntity.h"


// 只针对由特定技能触发的方法，如播放特效，造成伤害等。cd检查这种属于所有类型都要做的就不放在这里实现。
class SkillBase
{
public:
    SkillBase() {}
    virtual ~SkillBase() {}

    virtual void preCast(const PlayerEntity& player);
    virtual void cast(const PlayerEntity& fromEntity);
};