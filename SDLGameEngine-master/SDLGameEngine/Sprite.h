#pragma once
#include <iostream>
#include "Color.h"
#include "Rect.h"
class Sprite
{
public:
	Sprite();
	Sprite(std::string _imagePath, Rect * _clipFrame =  NULL);
	~Sprite();

	const std::string& GetPath();
	const Rect* const GetClipFrame();

private:
	std::string imagePath;
	Rect* clipFrame;
};

