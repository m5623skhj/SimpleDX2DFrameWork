#pragma once
#include "Object.h"

class MoveableObject : public Object
{
public:
	MoveableObject() = delete;
	explicit MoveableObject(ObjectId inObjectId, Position& inPosition);
	virtual ~MoveableObject() override = default;

public:
	void MoveTo(const Position& targetDestination);
	void MoveTo(Position&& targetDestination);

private:
	Position nowMoveDestination = {};
};