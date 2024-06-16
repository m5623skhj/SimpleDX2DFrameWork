#pragma once
#include "Define.h"

class SkillBase
{
public:
	virtual ~SkillBase();

public:
	virtual bool UseSkill() = 0;

private:
	SkillId skillId = InvalidId;
};