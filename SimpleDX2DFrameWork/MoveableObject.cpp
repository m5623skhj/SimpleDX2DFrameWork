#include "PreCompile.h"
#include "MoveableObject.h"

MoveableObject::MoveableObject(ObjectId inObjectId, Position& inPosition)
	: Object(inObjectId, inPosition)
{
}

void MoveableObject::MoveTo(const Position& targetDestination)
{
	nowMoveDestination = targetDestination;
}

void MoveableObject::MoveTo(Position&& targetDestination)
{
	nowMoveDestination = std::move(targetDestination);
}