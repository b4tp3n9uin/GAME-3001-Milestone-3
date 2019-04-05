#pragma once
#include <list>
#include "Behaviour.h"
#include "Vector2.h"
#include "SteeringBehaviour.h"
using namespace std;

class SteeringAgent : public Behaviour {
public:
	SteeringAgent();
	~SteeringAgent();
	SteeringAgent(GameObject* go);

	void Update();

	float maxSpeed = 100;
	float maxRotation = 0.1f;
	list<SteeringBehaviour*> steerings;

	Vector2 velocity;
	float angularSpeed;
};