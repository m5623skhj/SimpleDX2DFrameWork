#pragma once
#include "Define.h"

class Camera
{
private:
	Camera() = default;
	~Camera() = default;
	Camera(const Camera& other) = delete;
	Camera& operator=(const Camera& other) = delete;

public:
	static Camera& GetInst()
	{
		static Camera instance;
		return instance;
	}

public:
	void Initialize();

public:
	void InitPositionFromPlayer(WORD playerPosX, WORD playerPosY);
	void SetPositionFromPlayer(WORD playerPosX, WORD playerPosY);

	void GetCameraPosition(OUT WORD& outPosX, OUT WORD& outPosY);
	void SetMapRange(const MapRange& inMapRange);

private:
	WORD cameraPosX = 0;
	WORD cameraPosY = 0;

private:
	MapRange mapRange;
};