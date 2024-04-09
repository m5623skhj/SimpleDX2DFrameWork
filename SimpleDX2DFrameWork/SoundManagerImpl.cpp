#include "PreCompile.h"
#include "SoundManagerImpl.h"

void SoundManagerImpl::Initialize()
{
}

bool SoundManagerImpl::LoadBackgroundMusicFile(std::string_view soundFolderPath, std::string_view soundFilePath)
{
	std::string fileFullPath = "";
	fileFullPath += soundFolderPath;
	fileFullPath += soundFilePath;

	FMOD_SOUND* newSound = nullptr;
	auto result = FMOD_System_CreateSound(SoundManager::GetInst().fmodSystem, fileFullPath.c_str(), FMOD_2D | FMOD_LOOP_NORMAL, NULL, &newSound);
	if (result != FMOD_RESULT::FMOD_OK || newSound == nullptr)
	{
		return false;
	}

	soundMap.insert({ soundFilePath, newSound });
	return true;
}

bool SoundManagerImpl::LoadSoundEffectFile(std::string_view soundFolderPath, std::string_view soundFilePath)
{
	std::string fileFullPath = "";
	fileFullPath += soundFolderPath;
	fileFullPath += soundFilePath;

	FMOD_SOUND* newSound = nullptr;
	auto result = FMOD_System_CreateSound(SoundManager::GetInst().fmodSystem, fileFullPath.c_str(), FMOD_2D | FMOD_LOOP_OFF, NULL, &newSound);
	if (result != FMOD_RESULT::FMOD_OK || newSound == nullptr)
	{
		return false;
	}

	soundMap.insert({ soundFilePath, newSound });
	return true;
}

void SoundManagerImpl::ReleaseSound(std::string_view releaseSound)
{
	auto itor = soundMap.find(releaseSound);
	if (itor == soundMap.end() || itor->second == nullptr)
	{
		return;
	}

	FMOD_Sound_Release(itor->second);
}

void SoundManagerImpl::UpdateSound()
{
	FMOD_System_Update(SoundManager::GetInst().fmodSystem);
}

bool SoundManagerImpl::StartBackgroundMusic(std::string_view targetBackgroundMusic)
{
	auto itor = soundMap.find(targetBackgroundMusic);
	if (itor == soundMap.end() || itor->second == nullptr)
	{
		return false;
	}

	return FMOD_System_PlaySound(SoundManager::GetInst().fmodSystem, itor->second, NULL, false, &channelArray[backgroundMusicChannelIndex])
		== FMOD_RESULT::FMOD_OK;
}


bool SoundManagerImpl::StartSoundEffect(std::string_view targetSoundEffect)
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

	return FMOD_System_PlaySound(SoundManager::GetInst().fmodSystem, itor->second, NULL, false, &channelArray[channelPointer])
		== FMOD_RESULT::FMOD_OK;
}

void SoundManagerImpl::StopMusic(int stopSoundChannel)
{
	if (stopSoundChannel >= soundChannelMax)
	{
		return;
	}

	FMOD_Channel_Stop(channelArray[stopSoundChannel]);
}