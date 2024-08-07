#pragma once
#include "DataObjectBase.h"
#include "DataMacro.h"
#include <string>
#include "../inc/fmod.h"

class SoundManager
{
	friend class SoundData;
	friend class SoundManagerImpl;

private:
	SoundManager();
	SoundManager(const SoundManager& other) = delete;
	SoundManager& operator=(const SoundManager& other) = delete;
	~SoundManager();

private:
	static SoundManager& GetInst()
	{
		static SoundManager instance;
		return instance;
	}

private:
	FMOD_SYSTEM* fmodSystem;
};

class SoundData : public DataObjectBase
{
public:
	std::string soundName = "";

public:
	SET_DATA_OBJECT(SoundData, soundName);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		soundName = jsonObject["soundName"];
	}

	virtual bool PostLoad()
	{
		return CreateSound();
	}

public:
	FMOD_SOUND *sound;

private:
	bool CreateSound();
};