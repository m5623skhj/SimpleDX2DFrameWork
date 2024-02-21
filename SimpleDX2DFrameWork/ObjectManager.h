#pragma once
#include <unordered_map>
#include <shared_mutex>
#include "Define.h"

class Object;

class ObjectManager
{
private:
	ObjectManager() = default;
	~ObjectManager() = default;
	ObjectManager(const ObjectManager& other) = delete;
	ObjectManager& operator=(const ObjectManager& other) = delete;

public:
	static ObjectManager& GetInst()
	{
		static ObjectManager instance;
		return instance;
	}
	void Initialize();

public:
	void UpdateObjects();
	void RenderObjects();

private:
	std::unordered_map<ObjectId, Object*> objectMap;
	std::shared_mutex objectMapLock;
};