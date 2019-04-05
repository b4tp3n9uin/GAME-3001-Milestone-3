#pragma once
#include "Collider.h"
#include "Vector2.h"
class BoxCollider :
	public Collider
{
public:
	BoxCollider();
	~BoxCollider();

	void SetDimension(const Vector2& _dimension);
	const Vector2& GetDimension();

	void FixedUpdate();

private:
	b2PolygonShape box;
	Vector2 dimension;
};

