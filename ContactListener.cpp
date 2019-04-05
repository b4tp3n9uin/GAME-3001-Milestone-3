#include "ContactListener.h"
#include "Game.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "Collision.h"
#include "Collider.h"
#include "Physics.h"



void ContactListener::BeginContact(b2Contact* contact)
{
	auto col1 = static_cast<Collider*>(contact->GetFixtureA()->GetUserData());
	auto col2 = static_cast<Collider*>(contact->GetFixtureB()->GetUserData());

	auto rb1 = static_cast<Rigidbody*>(contact->GetFixtureA()->GetBody()->GetUserData());
	auto rb2 = static_cast<Rigidbody*>(contact->GetFixtureB()->GetBody()->GetUserData());
	
 	if (contact->GetFixtureA()->IsSensor() || contact->GetFixtureB()->IsSensor())
	{
		col1->gameObject->OnTriggerEnter(col2);
		if (rb1->gameObject != col1->gameObject)
		{
			rb1->gameObject->OnTriggerEnter(col2);
		}
		col2->gameObject->OnTriggerEnter(col1);
		if (rb2->gameObject != col2->gameObject)
		{
			rb2->gameObject->OnTriggerEnter(col1);
		}

	}
	else
	{
		Collision collision;

		int numPoints = contact->GetManifold()->pointCount;

		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);

		Game* game = col1->game;

		for (int i = 0; i < numPoints; i++)
		{
			collision.contacts.push_back(game->physics->GetWorldCoordinates(worldManifold.points[i]));
		}


		if (rb1)
		{
			collision.rigidbody = rb2;
			collision.collider = col2;
			collision.normal = Vector2(worldManifold.normal.x, worldManifold.normal.y);
			rb1->gameObject->OnCollisionEnter(collision);
		}

		if (rb2)
		{
			collision.rigidbody = rb1;
			collision.collider = col1;
			collision.normal = -Vector2(worldManifold.normal.x, worldManifold.normal.y);
			rb2->gameObject->OnCollisionEnter(collision);
		}
	}
	
}


void ContactListener::EndContact(b2Contact* contact)
{
	auto col1 = static_cast<Collider*>(contact->GetFixtureA()->GetUserData());
	auto col2 = static_cast<Collider*>(contact->GetFixtureB()->GetUserData());

	auto rb1 = static_cast<Rigidbody*>(contact->GetFixtureA()->GetBody()->GetUserData());
	auto rb2 = static_cast<Rigidbody*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (contact->GetFixtureA()->IsSensor() || contact->GetFixtureB()->IsSensor())
	{
		col1->gameObject->OnTriggerExit(col2);
		if (rb1->gameObject != col1->gameObject)
		{
			rb1->gameObject->OnTriggerExit(col2);
		}
		col2->gameObject->OnTriggerExit(col1);
		if (rb2->gameObject != col2->gameObject)
		{
			rb2->gameObject->OnTriggerExit(col1);
		}

	}
	else
	{
		Collision collision;

		int numPoints = contact->GetManifold()->pointCount;

		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);

		Game* game = col1->game;

		for (int i = 0; i < numPoints; i++)
		{
			collision.contacts.push_back(game->physics->GetWorldCoordinates(worldManifold.points[i]));
		}


		if (rb1)
		{
			collision.rigidbody = rb2;
			collision.collider = col2;
			collision.normal = Vector2(worldManifold.normal.x, worldManifold.normal.y);
			rb1->gameObject->OnCollisionExit(collision);
		}

		if (rb2)
		{
			collision.rigidbody = rb1;
			collision.collider = col1;
			collision.normal = -Vector2(worldManifold.normal.x, worldManifold.normal.y);
			rb2->gameObject->OnCollisionExit(collision);
		}
	}
}
