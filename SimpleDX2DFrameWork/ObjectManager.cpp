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

void ObjectManager::ObjectNetworkProc(CNetServerSerializationBuf* packet)
{
	UNREFERENCED_PARAMETER(packet);
}