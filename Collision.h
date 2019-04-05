#pragma once
#include <list>
#include "Vector2.h"
#include "Bullet.h"
#include "GameObject.h"

class Rigidbody;
class Collider;
class Collision
{
public:
	Collision();
	~Collision();
	Rigidbody* rigidbody;
	Collider* collider;
	std::list<Vector2> contacts;
	Vector2 normal;
	Bullet* bullet;
};

