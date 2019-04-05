#include "Pursue.h"
#include "SteeringAgent.h"
#include "Time.h"

Pursue::Pursue() {

}


Pursue::~Pursue() {

}


Pursue::Pursue(GameObject* go) : SteeringBehaviour(go) {

}


void Pursue::Start() {
	lastTargetPosition = target->position;
}

void Pursue::Update() {
	// Call SteeringBehaviour's Update
	SteeringBehaviour::Update();

	// Calculate direction
	Vector2 direction = target->position - gameObject->transform->position;

	// Get distance
	float distance = direction.Length();

	// Get speed
	float speed = 0.5; //agent -> velocity.Length();

	// Calculate prediction
	float prediction = speed < distance / maxPredirection ? maxPredirection : distance / speed;

	// Calculate target direction
	Vector2 targetVel = (target->position - lastTargetPosition) * 60.0f;

	// Calculate direction to target
	steering.linear = target->position + targetVel * prediction - gameObject->transform->position;

	// maxAcceleration in that direction
	steering.linear.Normalize();
	steering.linear *= maxAcceleration;

	// Output steering
	steering.angular = 0;
	lastTargetPosition = target->position;

	// Make the AI move
	gameObject->transform->SetAbsolutePositionDelta(direction * speed * Time::DeltaTime());

	// Make the AI turn
	float angle = atan2(direction.y, direction.x);
	gameObject->transform->SetAbsoluteAngle(angle * 180.0f / M_PI);
}