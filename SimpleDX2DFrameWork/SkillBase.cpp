#include "PreCompile.h"
#include "SkillBase.h"
#include "FightableObject.h"

SkillBase::SkillBase(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: skillId(inSkillId)
	, owner(skillOwner)
{
}

SkillBase::~SkillBase()
{
}