#include "PreCompile.h"
#include "Object.h"

Object::Object(ObjectId inObjectId, Position& inPosition)
	: objectId(inObjectId)
	, position(inPosition)
{
}

void Object::SetPosition(const Position& inPosition)
{
	position = inPosition;
}

void Object::SetMoveSpeed(BYTE inMoveSpeed)
{
	moveSpeed = inMoveSpeed;
}