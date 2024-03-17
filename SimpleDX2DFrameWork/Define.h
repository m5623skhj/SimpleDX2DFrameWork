#pragma once


/////////////////////////////////////////////////////////////////////////
// screen
/////////////////////////////////////////////////////////////////////////
const int windowSizeX = 1024;
const int windowSizeY = 768;

const int halfOfCameraX = 512;
const int halfOfCameraY = 384;

const float fadInOutValue = 0.02f;


/////////////////////////////////////////////////////////////////////////
// rendering 
/////////////////////////////////////////////////////////////////////////
const int oneFrameMaxTime = 20;


/////////////////////////////////////////////////////////////////////////
// rendering 
/////////////////////////////////////////////////////////////////////////
const int soundChannelMin = 1;
const int soundChannelMax = 32;
const int backgroundMusicChannelIndex = 0;


/////////////////////////////////////////////////////////////////////////
// etc 
/////////////////////////////////////////////////////////////////////////
const int heartbeatThreadAwakenMillisec = 10000;


/////////////////////////////////////////////////////////////////////////
// type
/////////////////////////////////////////////////////////////////////////
using ObjectId = UINT64;
using PacketType = WORD;

struct MapRange
{
	WORD top;
	WORD bottom;
	WORD left;
	WORD right;
};

struct Position
{
	WORD posX;
	WORD posY;

	Position() = default;

	Position(const Position& in)
		: posX(in.posX), posY(in.posY)
	{
	}

	Position(Position&& in) noexcept
		: posX(in.posX), posY(in.posY)
	{
	}

	Position& operator=(Position&& in) noexcept
	{
		posX = in.posX;
		posY = in.posY;

		return *this;
	}

	void operator=(const POINT& point)
	{
		posX = static_cast<WORD>(point.x);
		posY = static_cast<WORD>(point.y);
	}

	Position operator+(const Position& other)
	{
		Position newPosition;
		newPosition.posX = this->posX + other.posX;
		newPosition.posY = this->posY + other.posY;

		return newPosition;
	}
};

#define OUT 