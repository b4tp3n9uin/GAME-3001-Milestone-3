#pragma once
#include "Behaviour.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"


struct Steering
{
	Vector2 linear;
	float angular;
	float weight = 1;
};

class SteeringAgent;
class SteeringBehaviour :
	public Behaviour
{
public:
	SteeringBehaviour();
	SteeringBehaviour(GameObject* go);
	~SteeringBehaviour();

	virtual void Start();
	virtual void Update();

	Steering steering;
	SteeringAgent* agent = NULL;
};