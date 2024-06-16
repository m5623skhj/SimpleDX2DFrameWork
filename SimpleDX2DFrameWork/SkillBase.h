#pragma once
#include "Define.h"

class SkillBase
{
public:
	SkillBase() = delete;
	explicit SkillBase(SkillId inSkillId);
	virtual ~SkillBase();

public:
	virtual bool UseSkill() = 0;

private:
	SkillId skillId = InvalidId;
};