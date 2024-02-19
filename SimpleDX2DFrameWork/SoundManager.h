#pragma once

class SoundManager
{
private:
	SoundManager() = default;
	~SoundManager() = default;
	SoundManager(const SoundManager& other) = delete;
	SoundManager& operator=(const SoundManager& other) = delete;

public:
	static SoundManager& GetInst()
	{
		static SoundManager instance;
		return instance;
	}

public:
	void Initialize();

};