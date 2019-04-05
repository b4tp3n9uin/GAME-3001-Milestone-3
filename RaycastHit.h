#pragma once
#include "Vector2.h"
class Collider;
class RaycastHit
{
public:
	RaycastHit();
	~RaycastHit();
	Collider* collider = nullptr;
	Vector2 point;
	Vector2 normal;
};

