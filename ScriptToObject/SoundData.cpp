#include "PreCompile.h"
#include "SoundData.h"
#include "Define.h"

SoundManager::SoundManager()
{
	FMOD_System_Create(&fmodSystem);
	FMOD_System_Init(fmodSystem, soundChannelMax, FMOD_INIT_NORMAL, NULL);
}

SoundManager::~SoundManager()
{
	FMOD_System_Close(fmodSystem);
	FMOD_System_Release(fmodSystem);
}