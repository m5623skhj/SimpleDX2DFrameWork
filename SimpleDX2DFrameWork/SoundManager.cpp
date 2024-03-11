#include "PreCompile.h"
#include "SoundManager.h"

SoundManager::~SoundManager()
{
	FMOD_System_Close(fmodSystem);
	FMOD_System_Release(fmodSystem);
}

void SoundManager::Initialize()
{
	FMOD_System_Create(&fmodSystem);
	FMOD_System_Init(fmodSystem, soundChannelMax, FMOD_INIT_NORMAL, NULL);
}

bool SoundManager::LoadSoundData()
{
	// LoadBackgroundMusicFile("BackgroundMusic");
	// LoadSoundEffectFile("SoundEffect");
	// etc ...

	return true;
}

bool SoundManager::LoadBackgroundMusicFile(std::string_view soundFolderPath, std::string_view soundFilePath)
{
	std::string fileFullPath = "";
	fileFullPath += soundFolderPath;
	fileFullPath += soundFilePath;

	FMOD_SOUND* newSound = nullptr;
	auto result = FMOD_System_CreateSound(fmodSystem, fileFullPath.c_str(), FMOD_2D | FMOD_LOOP_NORMAL, NULL, &newSound);
	if (result != FMOD_RESULT::FMOD_OK || newSound == nullptr)
	{
		return false;
	}

	soundMap.insert({ soundFilePath, newSound });
	return true;
}

bool SoundManager::LoadSoundEffectFile(std::string_view soundFolderPath, std::string_view soundFilePath)
{
	std::string fileFullPath = "";
	fileFullPath += soundFolderPath;
	fileFullPath += soundFilePath;

	FMOD_SOUND* newSound = nullptr;
	auto result = FMOD_System_CreateSound(fmodSystem, fileFullPath.c_str(), FMOD_2D | FMOD_LOOP_OFF, NULL, &newSound);
	if (result != FMOD_RESULT::FMOD_OK || newSound == nullptr)
	{
		return false;
	}

	soundMap.insert({ soundFilePath, newSound });
	return true;
}

void SoundManager::ReleaseSound(std::string_view releaseSound)
{
	auto itor = soundMap.find(releaseSound);
	if (itor == soundMap.end() || itor->second == nullptr)
	{
		return;
	}

	FMOD_Sound_Release(itor->second);
}

void SoundManager::UpdateSound()
{
	FMOD_System_Update(fmodSystem);
}

bool SoundManager::StartBackgroundMusic(std::string_view targetBackgroundMusic)
{
	auto itor = soundMap.find(targetBackgroundMusic);
	if (itor == soundMap.end() || itor->second == nullptr)
	{
		return false;
	}

	return FMOD_System_PlaySound(fmodSystem, itor->second, NULL, false, &channelArray[backgroundMusicChannelIndex])
		== FMOD_RESULT::FMOD_OK;
}


bool SoundManager::StartSoundEffect(std::string_view targetSoundEffect)
{
	++channelPointer;
	if (channelPointer >= soundChannelMax)
	{
		channelPointer = soundChannelMin;
	}

	auto itor = soundMap.find(targetSoundEffect);
	if (itor == soundMap.end() || itor->second == nullptr)
	{
		return false;
	}

	return FMOD_System_PlaySound(fmodSystem, itor->second, NULL, false, &channelArray[channelPointer])
		== FMOD_RESULT::FMOD_OK;
}

void SoundManager::StopMusic(int stopSoundChannel)
{
	if (stopSoundChannel >= soundChannelMax)
	{
		return;
	}

	FMOD_Channel_Stop(channelArray[stopSoundChannel]);
}