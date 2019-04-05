#include "BoxCollider.h"
#include "Game.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "Transform.h"

BoxCollider::BoxCollider()
{
	fixtureDef.shape = &box;
}


BoxCollider::~BoxCollider()
{
}

void BoxCollider::SetDimension(const Vector2& _dimension)
{
	dimension = _dimension;
	b2Vec2 physicsDimension = game->physics->GetPhysicsCoordinates(_dimension);
	box.SetAsBox(physicsDimension.x / 2, physicsDimension.y / 2);
	fixtureDef.shape = &box;
	if (rigidbody)
	{
		if (fixture)
		{
			rigidbody->RemoveCollider(this);
		}
		rigidbody->AddCollider(this);
	}
	
}

const Vector2& BoxCollider::GetDimension()
{
	return dimension;
}

void BoxCollider::FixedUpdate()
{
	Collider::FixedUpdate();
	SDL_SetRenderDrawColor(Game::gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	Vector2 cam = Vector2(Camera::x, Camera::y);
	Vector2 a = gameObject->transform->GetAbsolutePosition() + gameObject->transform->Up() * dimension.y / 2 - gameObject->transform->Right() * dimension.x / 2 - cam;
	Vector2 b = gameObject->transform->GetAbsolutePosition() + gameObject->transform->Up() * dimension.y / 2 + gameObject->transform->Right() * dimension.x / 2 - cam;
	Vector2 c = gameObject->transform->GetAbsolutePosition() - gameObject->transform->Up() * dimension.y / 2 + gameObject->transform->Right() * dimension.x / 2 - cam;
	Vector2 d = gameObject->transform->GetAbsolutePosition() - gameObject->transform->Up() * dimension.y / 2 - gameObject->transform->Right() * dimension.x / 2 - cam;
	SDL_RenderDrawLine(Game::gRenderer, a.x, a.y, b.x, b.y);
	SDL_RenderDrawLine(Game::gRenderer, b.x, b.y, c.x, c.y);
	SDL_RenderDrawLine(Game::gRenderer, c.x, c.y, d.x, d.y);
	SDL_RenderDrawLine(Game::gRenderer, d.x, d.y, a.x, a.y);
}

