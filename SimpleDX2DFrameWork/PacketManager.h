#pragma once
#include "Define.h"

class PacketManager
{
private:
	PacketManager() = default;
	~PacketManager() = default;
	PacketManager(const PacketManager& other) = delete;
	PacketManager& operator=(const PacketManager& other) = delete;

public:
	static PacketManager& GetInst()
	{
		static PacketManager instance;
		return instance;
	}
	void Initialize();
};