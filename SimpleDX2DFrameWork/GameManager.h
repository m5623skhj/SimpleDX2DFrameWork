#pragma once

class GameManager
{
private:
	GameManager();
	~GameManager() = default;
	GameManager(const GameManager& other) = delete;
	GameManager& operator=(const GameManager& other) = delete;

public:
	static GameManager& GetInst()
	{
		static GameManager instance;
		return instance;
	}

private:
	void Initialize();

public:
	bool Update(bool windowActive);

private:
	void Render();
};