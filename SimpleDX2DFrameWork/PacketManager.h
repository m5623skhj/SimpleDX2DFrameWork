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

	// 패킷 타입에 따라서 패킷 핸들러를 미리 등록하도록 해야하나?
};