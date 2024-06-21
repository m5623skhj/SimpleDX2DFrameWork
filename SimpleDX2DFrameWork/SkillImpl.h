#pragma once
#include "SkillBase.h"
#include "Define.h"

class TargettingSkill : public SkillBase
{
public:
	TargettingSkill() = delete;
	explicit TargettingSkill(SkillId inSkillId);
	~TargettingSkill() override;

public:
	virtual bool UseSkill() override;
	void SetTargetObject(ObjectId inTargetObjectId) { targetObjectId = inTargetObjectId; }

private:
	ObjectId targetObjectId = InvalidObjectId;
};

class NonTargettingSkill : public SkillBase
{
public:
	NonTargettingSkill() = delete;
	explicit NonTargettingSkill(SkillId inSkillId);
	~NonTargettingSkill() override;

public:
	virtual bool UseSkill() override;
	void SetTargetPosition(Position&& inPosition) { targetPosition = std::move(inPosition); }

private:
	Position targetPosition{};
};

class RangeSkill : public SkillBase
{
public:
	RangeSkill() = delete;
	explicit RangeSkill(SkillId inSkillId);
	~RangeSkill() override;

public:
	virtual bool UseSkill() override;

private:

};

class ChannelingSkill : public SkillBase
{
public:
	ChannelingSkill() = delete;
	explicit ChannelingSkill(SkillId inSkillId);
	~ChannelingSkill() override;

public:
	virtual bool UseSkill() override;

private:

};

class ItemSkill : public SkillBase
{
public:
	ItemSkill() = delete;
	explicit ItemSkill(SkillId inSkillId);
	~ItemSkill() override;

public:
	virtual bool UseSkill() override;

private:

};