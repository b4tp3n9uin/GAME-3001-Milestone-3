#include "Behaviour.h"



Behaviour::Behaviour()
{
}

Behaviour::Behaviour(GameObject* _gameObject) : Component(_gameObject)
{

}

void Behaviour::Awake()
{
	Component::Awake();
}

void Behaviour::Start()
{
	Component::Start();
}

void Behaviour::Update()
{
	Component::Update();
}

void Behaviour::FixedUpdate()
{
	Component::Update();
}


void Behaviour::Cleanup()
{
	Component::Cleanup();
}

Behaviour::~Behaviour()
{
}
