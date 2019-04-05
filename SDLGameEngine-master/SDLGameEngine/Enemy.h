#pragma once
#include "EventListener.h"
#include "Behaviour.h"
#include "Collider.h"
class Enemy :
	public Behaviour
{
public:
	Enemy();
	~Enemy();

	float eSpeed = 80;
	float destroyTime = 1.2f;
	Vector2 eDirection;

	void Update();
	void Awake();
	void Cleanup();
	std::shared_ptr<EventListener<Collider*>> triggerEventListener = NULL;
	void OnTriggerEnter(Collider* col);
private:
	float timer = 0;
};

