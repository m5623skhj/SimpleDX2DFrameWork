#include "PreCompile.h"
#include "PlayerController.h"

PlayerController::PlayerController(PC& inControlledPC)
	: controlledPC(inControlledPC)
{
}

void PlayerController::MoveTo(Position&& inToPosition)
{
	movePosition = std::move(inToPosition);
	// TODO : Send to Server MoveToPacket
}