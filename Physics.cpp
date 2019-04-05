#include "Physics.h"
#include "Rigidbody.h"
#include "Time.h"
#include "Ray.h"
#include "RaycastHit.h"
#include "Game.h"
#include "Rect.h"

Physics::Physics()
{
	/*rigidbodies = std::list<Rigidbody*>();
	colliders = std::list<Collider*>();*/
}


Physics::~Physics()
{
}

void Physics::Start()
{
	world.SetContactListener(&contactListener);
}

void Physics::FixedUpdate()
{
	world.Step(Time::FixedDeltaTime(), velocityIterations, positionIterations);
}

void Physics::SetGravity(const Vector2& _gravity)
{
	gravity = _gravity;
	world.SetGravity(GetPhysicsCoordinates(gravity));
}


const b2Vec2 Physics::GetPhysicsCoordinates(const Vector2& pos)
{
	return b2Vec2(pos.x / worldScale, pos.y / worldScale);
}
const Vector2 Physics::GetWorldCoordinates(const b2Vec2& pos)
{
	return Vector2(pos.x * worldScale, pos.y * worldScale);
}

b2World& Physics::GetPhysicsWorld()
{
	return world;
}

void Physics::Extrapolate(float dt)
{
	// Remove rigidbody list and just go through world.GetBodyList()
	for (auto rigidbody : rigidbodies)
	{
		if (rigidbody != NULL)
		{
			rigidbody->Extrapolate(dt);
		}
	}
}

RaycastHit Physics::Raycast(Vector2 origin, Vector2 direction, float maxDistance, uint16_t layerMask, bool queriesHitTriggers)
{
	b2RayCastInput input;
	input.p1 = GetPhysicsCoordinates(origin);
	input.p2 = GetPhysicsCoordinates(origin + direction * maxDistance);
	input.maxFraction = 1;

	RaycastHit hit;

	//b2RayCastOutput output;
	//check every fixture of every body to find closest
	float closestFraction = 1; 
	for (b2Body* b = world.GetBodyList(); b; b = b->GetNext()) {
		for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {

			b2RayCastOutput output;
			if (!f->RayCast(&output, input, 0))
				continue;
			uint16_t l = layerMask & f->GetFilterData().categoryBits;
			if (output.fraction < closestFraction && ((layerMask & f->GetFilterData().categoryBits) != 0) && (queriesHitTriggers || !f->IsSensor())) {

				hit.collider = static_cast<Collider*>(f->GetUserData());
				hit.normal = Vector2(output.normal.x, output.normal.y);
				hit.point = origin + output.fraction * maxDistance * direction;
				closestFraction = output.fraction;
			}
		}
	}
	if (hit.collider != nullptr)
	{
		SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(Game::gRenderer, origin.x - Camera::x, origin.y - Camera::y, hit.point.x - Camera::x, hit.point.y - Camera::y);
		SDL_RenderDrawRect(Game::gRenderer, new Rect(hit.point.x - Camera::x - 5, hit.point.y - Camera::y - 5, 10, 10));
	}

	return hit;
}

RaycastHit Physics::Raycast(Ray ray, float maxDistance, uint16_t layerMask, bool queriesHitTriggers)
{
	return Raycast(ray.origin, ray.direction, maxDistance, layerMask, queriesHitTriggers);
}

