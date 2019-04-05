#pragma once
#include<iostream>
#include "SDL_image.h"

typedef struct Color : SDL_Color
{
	Color();
	Color(int8_t _r, int8_t _g, int8_t _b, int8_t _a);
	~Color();

	//uint8_t r;
	//uint8_t g;
	//uint8_t b;
	//uint8_t a;

	////ASSINGMENT AND EQUALITY OPERATIONS
	//inline Color & operator = (const Color & c) { r = c.r; g = c.g; b = c.b; a = c.a; return *this; }
	//inline bool operator == (const Color & c) const { return (r == c.r) && (g == c.g) && (b == c.b) && (a == c.a); }
	//inline bool operator != (const Color & c) const { return (r != c.r) && (g != c.g) && (b != c.b) && (a != c.a); }
}Color;

