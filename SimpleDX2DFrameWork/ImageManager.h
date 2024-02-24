#pragma once

class ImageManager
{
private:
	ImageManager() = default;
	~ImageManager() = default;
	ImageManager(const ImageManager& other) = delete;
	ImageManager& operator=(const ImageManager& other) = delete;

public:
	static ImageManager& GetInst()
	{
		static ImageManager instance;
		return instance;
	}

public:
	void Initialize();
};