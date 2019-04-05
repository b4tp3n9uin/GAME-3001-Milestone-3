#pragma once
#include "SteeringBehaviour.h"

class Pursue : public SteeringBehaviour {
public:
	Pursue();
	~Pursue();

	Pursue(GameObject* go);

	virtual void Start();
	virtual void Update();

	Transform* target;
	float maxAcceleration = 100;
	float maxPredirection = 10;

private:
	Vector2 lastTargetPosition;

};