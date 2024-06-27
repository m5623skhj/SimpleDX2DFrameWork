#pragma once
#include "Define.h"
#include "PC.h"

class PlayerController
{
public:
	PlayerController() = delete;
	explicit PlayerController(PC& inControlledPC);
	~PlayerController() = default;

public:
	ObjectId GetPlayerObjectId() { return controlledPC.GetObjectId(); }

private:
	PC& controlledPC;
};