#pragma once
#include <unordered_map>
#include <shared_mutex>
#include "Define.h"
#include "ManagerDefine.h"

class Object;
class CNetServerSerializationBuf;

class ObjectManager
{
	NON_COPYABLE(ObjectManager);

public:
	void Initialize();

public:
	void UpdateObjects();
	void RenderObjects();

	void ObjectNetworkProc(CNetServerSerializationBuf& packet);

private:
	void PacketHandle(PacketProtocolType packetType, CNetServerSerializationBuf& packet);

	// Define packet handler in here
	// Define packet handler in here

private:
	inline bool IsInvalidPacketType(WORD packetType) { return packetType >= static_cast<unsigned short>(PacketProtocolType::Max); }

private:
	std::unordered_map<ObjectId, std::shared_ptr<Object>> objectMap;
};