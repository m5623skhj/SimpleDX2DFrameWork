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

	void ObjectNetworkProc(CNetServerSerializationBuf* packet);

private:
	std::unordered_map<ObjectId, Object*> objectMap;
	std::shared_mutex objectMapLock;
};