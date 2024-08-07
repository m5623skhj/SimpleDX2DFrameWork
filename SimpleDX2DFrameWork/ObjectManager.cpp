#include "PreCompile.h"
#include "ObjectManager.h"
#include "Object.h"
#include "NetServerSerializeBuffer.h"
#include "PacketManager.h"

void ObjectManager::Initialize()
{
	PacketManager::GetInst().Initialize();
}

void ObjectManager::UpdateObjects()
{

}

void ObjectManager::RenderObjects()
{

}

void ObjectManager::ObjectNetworkProc(CNetServerSerializationBuf& packet)
{
	WORD type;
	packet >> type;

	if (IsInvalidPacketType(type))
	{
		return;
	}

	PacketHandle(static_cast<PacketProtocolType>(type), packet);
}

void ObjectManager::PacketHandle(PacketProtocolType packetType, CNetServerSerializationBuf& packet)
{
    switch (packetType)
    {
    default:
        break;
    }
}
