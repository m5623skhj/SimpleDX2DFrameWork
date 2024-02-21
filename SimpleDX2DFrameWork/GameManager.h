#pragma once

class GameClient;

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

private:
	GameClient* gameClient;

#pragma region Update
public:
	bool Update(bool windowActive);

private:
	void UpdateObjectFromNetwork();
	bool CalculateCheckTime();
	void Render();

private:
	DWORD beforeTime;
	DWORD checkTime;
	DWORD restTime;
#pragma endregion Update
};