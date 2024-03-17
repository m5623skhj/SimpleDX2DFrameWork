#pragma once
#include "Define.h"

class Object
{
public:
	Object() = delete;
	explicit Object(ObjectId inObjectId, Position& inPosition);
	virtual ~Object() = default;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	void SetPosition(Position&& inPosition);
	void SetMoveSpeed(BYTE inMoveSpeed);

protected:
	ObjectId objectId;

protected:
	Position position;
	// Get from server? Or client data?
	BYTE moveSpeed;
};