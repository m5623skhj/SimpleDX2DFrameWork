#pragma once
#include "MoveableObject.h"

class FightableObject : public MoveableObject
{
public:
	FightableObject() = delete;
	explicit FightableObject(ObjectId inObjectId, Position& inPosition, int inHp, bool inIsDie);
	virtual ~FightableObject() override = default;

public:
	virtual void UseSkill(/* need skill class? */);
	virtual void OnDamage(int damage, ObjectId attackerObjectId);
	virtual void Die(ObjectId attackerObjectId);

protected:
	int hp;
	bool isDie = false;
};