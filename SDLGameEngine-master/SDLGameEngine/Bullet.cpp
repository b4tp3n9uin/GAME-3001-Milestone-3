#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Behaviour.h"
#include "Time.h"
#include "Game.h"
using namespace std;

Bullet::Bullet() {
}


Bullet::~Bullet() {
}


void Bullet::Awake() {
	Behaviour::Awake();
	triggerEventListener = make_shared<EventListener<Collider*>>(bind(&Bullet::OnTriggerEnter, this, placeholders::_1));
	gameObject->OnTriggerEnter.AddListener(triggerEventListener);
}

void Bullet::Cleanup() {
	Behaviour::Cleanup();
	gameObject->OnTriggerEnter.RemoveListener(triggerEventListener);
}


void Bullet::Update() {
	Behaviour::Update();
	Vector2 up = gameObject->transform->Up();
	gameObject->transform->SetAbsolutePositionDelta(bSpeed * up * Time::DeltaTime());

	timer += Time::DeltaTime();
	if (timer > destroyTime) {
		game->Destroy(gameObject);
	}
}


void Bullet::OnTriggerEnter(Collider* col) {
	if (col -> gameObject -> name == "Enemy") {
		//game -> Destroy(col -> gameObject);
		//game->Destroy(gameObject);
	}
}