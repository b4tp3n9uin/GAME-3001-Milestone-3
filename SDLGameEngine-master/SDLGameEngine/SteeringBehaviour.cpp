#include "SteeringBehaviour.h"
#include "Game.h"


SteeringBehaviour::SteeringBehaviour()
{
}

SteeringBehaviour::SteeringBehaviour(GameObject* go) : Behaviour(go)
{
}

SteeringBehaviour::~SteeringBehaviour()
{
}

void SteeringBehaviour::Start()
{

}

void SteeringBehaviour::Update()
{
	/*SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(Game::gRenderer, gameObject->transform->position.x, gameObject->transform->position.y, gameObject->transform->position.x + steering.linear.x * 30, gameObject->transform->position.y + steering.linear.y * 30);*/
	Behaviour::Update();
}