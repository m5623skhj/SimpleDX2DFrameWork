#pragma once
#include "Object.h"

class FightableObject : public Object
{
public:
	FightableObject() = default;
	virtual ~FightableObject() override = default;

public:
	virtual void UseSkill(/* need skill class? */);
	virtual void OnDamage(int damage, ObjectId attackerObjectId);
	virtual void Die(ObjectId attackerObjectId);

protected:
	int hp;
	bool isDie = false;
};