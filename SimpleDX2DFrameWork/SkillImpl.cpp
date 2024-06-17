#include "PreCompile.h"
#include "SkillImpl.h"

TargettingSkill::TargettingSkill(SkillId inSkillId)
	: SkillBase(inSkillId)
{
}

TargettingSkill::~TargettingSkill()
{
}

bool TargettingSkill::UseSkill()
{
	return true;
}

NonTargettingSkill::NonTargettingSkill(SkillId inSkillId)
	: SkillBase(inSkillId)
{
}

NonTargettingSkill::~NonTargettingSkill()
{
}

bool NonTargettingSkill::UseSkill()
{
	return true;
}

RangeSkill::RangeSkill(SkillId inSkillId)
	: SkillBase(inSkillId)
{
}

RangeSkill::~RangeSkill()
{
}

bool RangeSkill::UseSkill()
{
	return true;
}

ChannelingSkill::ChannelingSkill(SkillId inSkillId)
	: SkillBase(inSkillId)
{
}

ChannelingSkill::~ChannelingSkill()
{
}

bool ChannelingSkill::UseSkill()
{
	return true;
}

ItemSkill::ItemSkill(SkillId inSkillId)
	: SkillBase(inSkillId)
{
}

ItemSkill::~ItemSkill()
{
}

bool ItemSkill::UseSkill()
{
	return true;
}
