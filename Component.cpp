#include "Component.h"
#include <iostream>
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Scene.h"


Component::Component()
{
	
}

Component::Component(GameObject* _gameObject)
{
	gameObject = _gameObject;
}


Component::~Component()
{
	
}

void Component::Awake()
{
	awoken = true;
}

void Component::Start()
{

}

void Component::Update()
{

}

void Component::FixedUpdate()
{

}

void Component::Cleanup()
{

}

GameObject* Component::Instantiate(std::string name, const float& x, const float& y, const float& angle)
{
	if (scene != NULL)
	{
		return scene->Instantiate(name, x, y, angle);
	}
	else
	{
		return game->Instantiate(name, x, y, angle);
	}
}

GameObject* Component::Instantiate(GameObject* go, const float& x, const float& y, const float& angle)
{
	if (scene != NULL)
	{
		return scene->Instantiate(go, x, y, angle);
	}
	else
	{
		return game->Instantiate(go, x, y, angle);
	}
}

GameObject* Component::Instantiate(std::string name, const Vector2& position, const float& angle)
{
	return Instantiate(name, position.x, position.y, angle);
}

GameObject* Component::Instantiate(GameObject* go, const Vector2& position, const float& angle)
{
	return Instantiate(go, position.x, position.y, angle);
}

void Component::OnUpdate()
{
	if (gameObject != nullptr)
	{
		if (!started)
		{
			Start();
			started = true;
		}
		else
		{
			Update();
		}
	}	
}


