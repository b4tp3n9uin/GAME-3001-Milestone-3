#include "Collider.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "Game.h"
#include "Ray.h"
#include "RaycastHit.h"
#include "Rect.h"

Collider::Collider()
{

}


Collider::~Collider()
{
	
}

void Collider::Cleanup()
{
	if (rigidbody)
	{
		RemoveCollider(rigidbody);
	}
	gameObject->OnAddRigidbody.RemoveListener(OnRigidbodyAdded);
	//gameObject->OnRemoveRigidbody.RemoveListener(OnRigidbodyRemoved);
}

void Collider::Awake()
{
	if (gameObject->rigidbody)
	{
		AddCollider(gameObject->rigidbody);
	}
	OnRigidbodyAdded = std::make_shared<EventListener<Rigidbody*>>(std::bind(&Collider::RigidbodyAdded, this, std::placeholders::_1));
	//OnRigidbodyRemoved = std::make_shared<EventListener<Rigidbody*>>(std::bind(&RigidbodyRemoved, this));*/
	gameObject->OnAddRigidbody.AddListener(OnRigidbodyAdded);
	//gameObject->OnRemoveRigidbody.AddListener(OnRigidbodyRemoved);
}

void Collider::SetRigidBody()
{
	/*Transform* t = gameObject->transform;
	while (rigidbody == nullptr && t != nullptr)
	{
		rigidbody = t->gameObject->GetComponent<Rigidbody>();
		t = t->parent;
	}
	if (rigidbody && !rigidbody->ContainsCollider(this))
	{
		rigidbody->AddCollider(this);
	}*/
	AddCollider(gameObject->rigidbody);
}

void Collider::FixedUpdate()
{

	Component::FixedUpdate();
}

void Collider::SetTrigger(bool toggle)
{
	isTrigger = toggle;
	fixtureDef.isSensor = toggle;
	if (fixture)
	{
		fixture->SetSensor(toggle);
	}
}
bool Collider::GetTrigger()
{
	return isTrigger;
}

void Collider::SetCategory(uint16_t flags)
{
	if (fixture)
	{
		b2Filter filter = fixture->GetFilterData();
		filter.categoryBits = flags;
		fixture->SetFilterData(filter);
	}
	fixtureDef.filter.categoryBits = flags;
}

void Collider::SetCollisionMask(uint16_t flags)
{
	if (fixture)
	{
		b2Filter filter = fixture->GetFilterData();
		filter.maskBits = flags;
		fixture->SetFilterData(filter);
	}
	fixtureDef.filter.maskBits = flags;
}

RaycastHit Collider::Raycast(Vector2 origin, Vector2 direction, float maxDistance)
{
	b2RayCastInput input;
	input.p1 = game->physics->GetPhysicsCoordinates(origin);
	input.p2 = game->physics->GetPhysicsCoordinates(origin + direction * maxDistance);
	input.maxFraction = 1;

	RaycastHit hit;

	b2RayCastOutput output;
	if (fixture->RayCast(&output, input, 0))
	{
		hit.collider = this;
		hit.normal = Vector2(output.normal.x, output.normal.y);
		hit.point = origin + output.fraction * maxDistance * direction;

		SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, origin.x - Camera::x, origin.y - Camera::y, hit.point.x - Camera::x, hit.point.y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(hit.point.x - Camera::x - 5, hit.point.y - Camera::y - 5, 10, 10));
	}

	return hit;
}

RaycastHit Collider::Raycast(Ray ray, float maxDistance)
{
	return Raycast(ray.origin, ray.direction, maxDistance);
}

void Collider::AddCollider(Rigidbody* _rigidbody)
{
	_rigidbody->AddCollider(this);
	rigidbody = _rigidbody;
}

void Collider::RemoveCollider(Rigidbody* _rigidbody)
{
	_rigidbody->RemoveCollider(this);
	rigidbody = nullptr;
}

void Collider::RigidbodyAdded(Rigidbody* _rigidbody)
{
	if (_rigidbody != rigidbody)
	{
		if (rigidbody != nullptr)
		{
			RemoveCollider(rigidbody);
		}
		if (_rigidbody != nullptr)
		{
			AddCollider(_rigidbody);
		}
	}
}

//void Collider::RigidbodyRemoved(Rigidbody* _rigidbody)
//{
//	if (_rigidbody == rigidbody)
//	{
//		RemoveCollider(rigidbody);
//
//		if (gameObject->rigidbody != nullptr)
//		{
//			AddCollider(gameObject->rigidbody);
//		}
//	}
//}