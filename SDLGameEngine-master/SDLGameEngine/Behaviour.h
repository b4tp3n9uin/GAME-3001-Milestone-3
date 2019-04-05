#pragma once
#include "Component.h"

class Behaviour :
	public Component
{
public:
	Behaviour();
	Behaviour(GameObject* _gameObject);
	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Cleanup();
	virtual ~Behaviour();
};

