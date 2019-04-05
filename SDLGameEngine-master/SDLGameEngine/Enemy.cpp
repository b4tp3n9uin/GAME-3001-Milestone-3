#include "Enemy.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Behaviour.h"
#include "Pursue.h"
#include "Time.h"
#include "Game.h"
using namespace std;


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{

	timer += Time::DeltaTime();
	if (timer > destroyTime) {
		//game->Destroy(gameObject);
	}
}

void Enemy::Awake()
{
	Behaviour::Awake();
	triggerEventListener = make_shared<EventListener<Collider*>>(bind(&Enemy::OnTriggerEnter, this, placeholders::_1));
	gameObject->OnTriggerEnter.AddListener(triggerEventListener);
}

void Enemy::Cleanup()
{
	Behaviour::Cleanup();
	gameObject->OnTriggerEnter.RemoveListener(triggerEventListener);
}

void Enemy::OnTriggerEnter(Collider * col)
{
	if (col->gameObject->name == "Bullet") {
		game->Destroy(col->gameObject);
		game->Destroy(gameObject);
	}
}
