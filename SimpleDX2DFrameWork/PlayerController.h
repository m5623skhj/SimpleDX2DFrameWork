#pragma once
#include "Define.h"
#include "PC.h"

class PlayerController
{
public:
	PlayerController() = delete;
	explicit PlayerController(PC& inOwner);
	~PlayerController() = default;

public:
	ObjectId GetPlayerObjectId() { return owner.GetObjectId(); }

private:
	PC& owner;
};