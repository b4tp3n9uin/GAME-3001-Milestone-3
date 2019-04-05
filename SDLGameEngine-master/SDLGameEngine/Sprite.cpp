#include "Sprite.h"



Sprite::Sprite()
{
}


Sprite::Sprite(std::string _imagePath, Rect * _clipFrame)
{
	imagePath = _imagePath;
	clipFrame = _clipFrame;
}

Sprite::~Sprite()
{
}

const std::string& Sprite::GetPath()
{
	return imagePath;
}
const Rect* const Sprite::GetClipFrame()
{
	return clipFrame;
}
