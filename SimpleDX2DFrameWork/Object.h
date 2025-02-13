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
	ObjectId GetObjectId() const { return objectId; }
	void SetPosition(Position&& inPosition);

protected:
	ObjectId objectId;

protected:
	Position position;
};