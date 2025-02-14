#pragma once
#include <cstdint>

enum class KeyCode : int
{
	ClickLeft = 0,
	ClickRight,
	Enter,
	Esc,
	LeftShift,
	LeftCtrl,

	//--------------------------
	Q,
	W,
	E,
	R,
	A,
	S,
	D,
	F,
	Z,
	X,
	C,
	V,
	LeftArrow,
	RightArrow,
	UpArrow,
	DownArrow,
	//--------------------------

	// it must be last
	KeyCodeMax
};

enum class ObjectType : short
{
	PCType = 0,
	NPCType,
	MosnterType,
	InvalidType = INT16_MAX
};

enum class OnMouseType : char
{
	Normal = 0,
	OnCharacter,
	OnLoading,
	OnGrab,
	OnAttack,
	OnDoor,
	InvalidType = CHAR_MAX
};

enum class PacketProtocolType : unsigned short
{
	// define packet type on here
	Ping = 0,
	Pong,
	// define packet type on here

	Max
};