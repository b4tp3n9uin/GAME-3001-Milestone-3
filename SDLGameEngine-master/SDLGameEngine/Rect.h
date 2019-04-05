#pragma once
#include "SDL.h"
#include "SDL_image.h"

typedef struct Rect: SDL_Rect
{
	Rect();
	Rect(int _x, int _y, int _w, int _h);
	~Rect();
}Rect;

