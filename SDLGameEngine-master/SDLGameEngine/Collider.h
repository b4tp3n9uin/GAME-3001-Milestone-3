#pragma once
#include "Component.h"
#include <Box2D/Box2D.h>
#include "Event.h"

class Ray;
class RaycastHit;
class Rigidbody;
class Collider :
	public Component
{
public:
	Collider();
	virtual ~Collider();

	b2FixtureDef fixtureDef;
	b2Fixture* fixture;

	virtual void Awake();
	virtual void FixedUpdate();
	virtual void Cleanup();

	void SetRigidBody();

	void SetTrigger(bool toggle);
	bool GetTrigger();

	void SetCategory(uint16_t flags);
	void SetCollisionMask(uint16_t flags);

	RaycastHit Raycast(Ray ray, float maxDistance);
	RaycastHit Raycast(Vector2 origin, Vector2 direction, float maxDistance);

	void AddCollider(Rigidbody* rigidbody);
	void RemoveCollider(Rigidbody* rigidbody);

	std::shared_ptr<EventListener<Rigidbody*>> OnRigidbodyAdded = nullptr;
	//std::shared_ptr<EventListener<Rigidbody*>> OnRigidbodyRemoved = std::make_shared<EventListener<Rigidbody*>>(std::bind(&RigidbodyRemoved, this));

	void RigidbodyAdded(Rigidbody* rigidbody);
	//void RigidbodyRemoved(Rigidbody* rigidbody);

protected:
	bool isTrigger = false;
	Rigidbody* rigidbody = NULL;
};

