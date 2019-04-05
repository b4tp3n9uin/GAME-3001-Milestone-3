#pragma once
#include "Renderer.h"
#include <SDL_image.h>
#include "Sprite.h"

class SpriteRenderer :
	public Renderer
{
public:
	SpriteRenderer();
	SpriteRenderer(Sprite* _sprite, int _layer = 0);
	SpriteRenderer(std::string _imagePath, Rect * _clipFrame = NULL, int _layer = 0);
	~SpriteRenderer();

	void SetSprite(Sprite* _sprite);
	void Render();

	bool flipX;
	bool flipY;

	const int& GetWidth();
	const int& GetHeight();

	void SetColor(Color _color);

	void Cleanup();

private:
	bool LoadSprite();
	void FreeTexture();
	SDL_Texture* texture = NULL;
	Sprite* sprite = NULL;
	Color color;
	int width;
	int height;
	SDL_Point pivot;
	int lastXpos;
	int lastYpos;
};

