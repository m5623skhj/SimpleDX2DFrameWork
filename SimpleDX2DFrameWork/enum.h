#pragma once

enum KeyCode : int
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
	InvalidKeyCode = INT_MAX
};

enum ObjectType : short
{
	PCType = 0,
	NPCType,
	MosnterType,
	InvalidType = INT16_MAX
};

enum OnMouseType : char
{
	Normal = 0,
	OnCharacter,
	OnLoading,
	OnGrab,
	OnAttack,
	OnDoor,
	InvalidType = INT16_MAX
};