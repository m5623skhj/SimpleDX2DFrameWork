#pragma once
#include "Define.h"

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	void SetPosition(const Position& inPosition);

protected:
	ObjectId objectId;

protected:
	Position position;
	BYTE moveSpeed;
};