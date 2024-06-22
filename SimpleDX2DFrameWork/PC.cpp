#include "PreCompile.h"
#include "PC.h"

PC::PC(ObjectId inObjectId, Position& inPosition, int inHP, bool inIsDie)
	: FightableObject(inObjectId, inPosition, inHP, inIsDie)
{
}