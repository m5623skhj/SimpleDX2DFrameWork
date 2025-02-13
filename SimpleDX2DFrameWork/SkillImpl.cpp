#include "PreCompile.h"
#include "SkillImpl.h"

TargettingSkill::TargettingSkill(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: SkillBase(inSkillId, skillOwner)
{
}

TargettingSkill::~TargettingSkill()
{
}

bool TargettingSkill::UseSkill()
{
	return true;
}

NonTargettingSkill::NonTargettingSkill(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: SkillBase(inSkillId, skillOwner)
{
}

NonTargettingSkill::~NonTargettingSkill()
{
}

bool NonTargettingSkill::UseSkill()
{
	return true;
}

RangeSkill::RangeSkill(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: SkillBase(inSkillId, skillOwner)
{
}

RangeSkill::~RangeSkill()
{
}

bool RangeSkill::UseSkill()
{
	return true;
}

ChannelingSkill::ChannelingSkill(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: SkillBase(inSkillId, skillOwner)
{
}

ChannelingSkill::~ChannelingSkill()
{
}

bool ChannelingSkill::UseSkill()
{
	return true;
}

ItemSkill::ItemSkill(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner)
	: SkillBase(inSkillId, skillOwner)
{
}

ItemSkill::~ItemSkill()
{
}

bool ItemSkill::UseSkill()
{
	return true;
}
