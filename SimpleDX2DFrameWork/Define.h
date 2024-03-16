#pragma once


/////////////////////////////////////////////////////////////////////////
// screen
/////////////////////////////////////////////////////////////////////////
const int windowSizeX = 1024;
const int windowSizeY = 768;

const int halfOfCameraX = 512;
const int halfOfCameraY = 384;


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
};

#define OUT 