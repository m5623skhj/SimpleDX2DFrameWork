#pragma once
#include "Define.h"

class PlayerController
{
public:
	PlayerController() = default;
	~PlayerController() = default;

public:
	void SetMyPCObjectId(const ObjectId& inObjectId) { myPCObjectId = inObjectId; }
	ObjectId GetMyPCObjectId() { return myPCObjectId; }

private:
	ObjectId myPCObjectId = {};
};