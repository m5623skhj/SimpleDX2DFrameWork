#pragma once
#include "Define.h"

class FightableObject;

class SkillBase
{
public:
	SkillBase() = delete;
	explicit SkillBase(SkillId inSkillId, std::shared_ptr<FightableObject> skillOwner);
	virtual ~SkillBase();

public:
	virtual bool UseSkill() = 0;

private:
	SkillId skillId{ InvalidId };
	std::shared_ptr<FightableObject> owner{};
};