#pragma once
#include "FightableObject.h"

class PC : public FightableObject
{
public:
	PC() = delete;
	explicit PC(ObjectId inObjectId, Position& inPosition, int inHP, bool inIsDie);
	virtual ~PC() override = default;

public:

};