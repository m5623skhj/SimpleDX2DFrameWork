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

public:
	void MoveTo(Position&& inToPosition);

protected:
	Position GetMovePosition() { return movePosition; }

private:
	PC& controlledPC;
	Position movePosition{};
};