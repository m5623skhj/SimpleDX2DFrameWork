#pragma once
#include "SkillBase.h"
#include "Define.h"

class TargettingSkill : public SkillBase
{
public:
	TargettingSkill() = delete;
	explicit TargettingSkill(SkillId inSkillId);
	~TargettingSkill() override;

private:

};

class RangeSkill : public SkillBase
{
public:
	RangeSkill() = delete;
	explicit RangeSkill(SkillId inSkillId);
	~RangeSkill() override;

private:

};

class ItemSkill : public SkillBase
{
public:
	ItemSkill() = delete;
	explicit ItemSkill(SkillId inSkillId);
	~ItemSkill() override;

private:

};