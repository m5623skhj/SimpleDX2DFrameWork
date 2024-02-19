#pragma once

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
	void InitPositionFromPlayer(WORD palyerPosX, WORD playerPosY);
	void SetPositionFromPlayer(WORD playerPosX, WORD playerPosY);

	void GetCameraPosition(WORD& outPosX, WORD& outPosY);
	void SetMapRange(WORD top, WORD bottom, WORD left, WORD right);

private:
	WORD cameraPosX = 0;
	WORD cameraPosY = 0;
};