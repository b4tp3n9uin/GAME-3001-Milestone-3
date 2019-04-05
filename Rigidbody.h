#pragma once
#include <memory>
#include "Component.h"
#include "Physics.h"
//#include "EventListener.h"

class Collider;
class TransformData;
template <class T> class EventListener;
class Rigidbody
	: public Component
{
public:
	Rigidbody();
	virtual ~Rigidbody();

	void Awake();
	//void Start();
	void FixedUpdate();
	void Cleanup();

	enum bodyType
	{
		staticBody,
		kinematicBody,
		dynamicBody
	};

	void SetBodyType(const bodyType& _type);
	const bodyType& GetBodyType() const;

	b2Body* body;

	void Extrapolate(float dt);

	void AddForce(Vector2 force);
	void AddForce(Vector2 force, Vector2 point);

	void SetMass(float mass);
	float GetMass();

	const Vector2 GetVelocity();
	void SetVelocity(const Vector2& velocity);

	void SetBullet(bool toggle);

	bool ContainsCollider(Collider* col);
	void AddCollider(Collider* col);
	void RemoveCollider(Collider* col);

	std::shared_ptr<EventListener<TransformData>> onTransformUpdate = NULL;
private:
	b2BodyDef bodyDef;
	bool massChanged = false;
	float mass;
	bodyType type;
	Physics* physics;
	/*b2Transform physicsTransform;*/
	std::list<Collider*> myColliders;
	b2Vec2 accelaration;
	b2Vec2 lastVelocity;
	void UpdatePhysicsTransform(const TransformData &data);
	b2BodyType ConvertToB2Type(const bodyType& _type);
	bool isBullet = false;
};

