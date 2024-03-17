#include "PreCompile.h"
#include "Object.h"

Object::Object(ObjectId inObjectId, Position& inPosition)
	: objectId(inObjectId)
	, position(inPosition)
{
}

void Object::SetPosition(Position&& inPosition)
{
	position = std::move(inPosition);
}

void Object::SetMoveSpeed(BYTE inMoveSpeed)
{
	moveSpeed = inMoveSpeed;
}