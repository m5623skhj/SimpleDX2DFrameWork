#pragma once
#include "fmod.h"
#include "ManagerDefine.h"
#include "Define.h"
#include <string_view>
#include <unordered_map>

class SoundManager
{
	NON_COPYABLE_WITH_NON_DESTRUCTOR(SoundManager);
	~SoundManager();

public:
	void Initialize();

private:
	bool LoadSoundData();

	bool LoadBackgroundMusicFile(std::string_view soundFolderPath, std::string_view soundFilePath);
	bool LoadSoundEffectFile(std::string_view soundFolderPath, std::string_view soundFilePath);

private:
	void ReleaseSound(std::string_view releaseSound);

public:
	void UpdateSound();

public:
	bool StartBackgroundMusic(std::string_view targetBackgroundMusic);
	bool StartSoundEffect(std::string_view targetSoundEffect);
	void StopMusic(int stopSoundChannel);

private:
	FMOD_SYSTEM* fmodSystem;

	std::unordered_map<std::string_view, FMOD_SOUND*> soundMap;
	FMOD_CHANNEL* channelArray[soundChannelMax];

	int channelPointer = soundChannelMin;
};