#pragma once
#include <SDL.h>
#include <list>
#include "Component.h"
#include "Vector2.h"
#include "Event.h"
#include "TransformData.h"

class Transform :
	public Component
{
public:
	Transform();
	Transform(GameObject* _gameObject, float x = 0, float y = 0, float _angle = 0, float xScale = 1, float yScale = 1);
	~Transform();

	const Vector2& GetAbsolutePosition() const;
	const float& GetAbsoluteAngle() const;
	const Vector2& GetAbsoluteScale() const;

	const Vector2& GetRelativePosition() const;
	const float& GetRelativeAngle() const;
	const Vector2& GetRelativeScale() const;

	void SetAbsolutePosition(const Vector2& _position);
	void SetAbsoluteAngle(const float& _angle);
	void SetAbsoluteScale(const Vector2& _scale);

	void SetRelativePosition(const Vector2& _position);
	void SetRelativeAngle(const float& _angle);
	void SetRelativeScale(const Vector2& _scale);

	void SetAbsolutePositionDelta(const Vector2& delta);
	void SetAbsoluteAngleDelta(const float& delta);
	void SetAbsoluteScaleDelta(const Vector2& delta);

	void SetRelativePositionDelta(const Vector2& delta);
	void SetRelativeAngleDelta(const float& delta);
	void SetRelativeScaleDelta(const Vector2& delta);

	void SetParent(Transform* _parent);
	void SetParentRelative(Transform* _parent);

	std::list<Transform*> children;

	const Vector2 Right() const;
	const Vector2 Up() const;

	Transform* parent = NULL;

	Event<TransformData> OnTransformUpdate;

	void Cleanup();

	Vector2 position;
	float angle;
	Vector2 scale;

private:

	Vector2 relativePosition;
	float relativeAngle;
	Vector2 relativeScale;

	TransformData data;
};

