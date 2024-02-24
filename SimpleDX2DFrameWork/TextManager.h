#pragma once

class TextManager
{
private:
	TextManager() = default;
	~TextManager() = default;
	TextManager(const TextManager& other) = delete;
	TextManager& operator=(const TextManager& other) = delete;

public:
	static TextManager& GetInst()
	{
		static TextManager instance;
		return instance;
	}

public:
	void Initialize();
};