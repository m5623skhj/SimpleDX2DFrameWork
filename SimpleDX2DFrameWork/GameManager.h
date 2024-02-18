#pragma once

class GameManager
{
private:
	GameManager() = default;
	~GameManager() = default;
	GameManager(const GameManager& other) = delete;
	GameManager& operator=(const GameManager& other) = delete;

public:
	static GameManager& GetInst()
	{
		static GameManager instance;
		return instance;
	}

public:
	bool Update(bool windowActive);

private:
	void Render();
};