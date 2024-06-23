#include "PreCompile.h"
#include "FightableObject.h"

FightableObject::FightableObject(ObjectId inObjectId, Position& inPosition, int inHp, bool inIsDie)
	: MoveableObject(inObjectId, inPosition)
	, hp(inHp)
	, isDie(inIsDie)
{
}

void FightableObject::UseSkill(/* need skill class? */)
{

}

void FightableObject::OnDamage(int damage, ObjectId attackerObjectId)
{
	UNREFERENCED_PARAMETER(attackerObjectId);
	
	if (isDie == true)
	{
		return;
	}

	hp -= damage;
}

void FightableObject::Die(ObjectId attackerObjectId)
{
	UNREFERENCED_PARAMETER(attackerObjectId);
	isDie = true;
}
