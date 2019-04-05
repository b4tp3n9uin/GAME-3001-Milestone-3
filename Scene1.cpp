#include <iostream>
#include "Scene1.h"
#include "Camera.h"
#include "CameraFollow.h"
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"
#include "SpriteRenderer.h"
#include "PlayerControls.h"
#include "Physics.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "SteeringAgent.h"
#include "Pursue.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Game.h"
#include "Shoot.h"
#include "Enemy.h"
using namespace std;

Scene1::Scene1()
{
}


Scene1::~Scene1()
{
}

void Scene1::Setup()
{
	Scene::Setup();

	Rigidbody* rigid = new Rigidbody();

	// Collider from box 2d
	BoxCollider* col = new BoxCollider();

	// Static rigidbody
	rigid->SetBodyType(rigid->bodyType::staticBody);

	GameObject* bg = Instantiate("bg", 960, 540, 0);
	Sprite* bgSprite = new Sprite("Assets/snow.jpg");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);

	//GameObject* wall1 = Instantiate(game->Prefab("Wall"), 200, 400, 0);
	//Sprite* wallSprite = new Sprite("Assets/stone_wall.png");
	//SpriteRenderer* wallRenderer = new SpriteRenderer(wallSprite);
	//wall1->AddComponent(wallRenderer);

	GameObject* player = Instantiate("Player", Camera::width/2, Camera::height / 2);
	GameObject* playerGraphic = Instantiate("PlayerGraphic", 0, 0, 0);
	playerGraphic->transform->SetParentRelative(player->transform);
	playerGraphic->transform->SetAbsoluteScale(Vector2(0.5f, 0.5f));
	Sprite* playerSprite = new Sprite("Assets/Shooter.png");
	playerGraphic->AddComponent(new SpriteRenderer(playerSprite, 1));
	PlayerControls* control = new PlayerControls();
	control->speed = 300;

	player->AddComponent(control);
	player->AddComponent(rigid);

	for (int i = 0; i < 10; i++)
	{		
		GameObject* enemy = Instantiate("Enemy", rand() % Camera::width, rand() % Camera::height);
		//GameObject* enemyGraphic = Instantiate("EnemyGraphic", 0, 0, 0);

		Rigidbody* enemyRb = new Rigidbody();
		enemyRb->SetBodyType(Rigidbody::dynamicBody);
		enemy->AddComponent(enemyRb);
		BoxCollider* enemyCol = new BoxCollider();
		enemy->AddComponent(enemyCol);

		// Collider size and layer
		enemyCol->SetDimension(Vector2(70, 70));
		enemyCol->SetCategory(game->physics->Layer_3);

		// Set AI graphics
		//enemyGraphic->transform->SetParentRelative(enemy->transform);
		//enemyGraphic->transform->SetAbsoluteScale(Vector2(0.5f, 0.5f));
		//enemyGraphic->AddComponent(new SpriteRenderer("Assets/Polar_Bear.png"));
		//enemyGraphic->AddComponent(new Enemy());


		// Initialize AI behavior
		Pursue* pursue = new Pursue(enemy);
		pursue->target = player->transform;
		pursue->maxAcceleration = 10;
		enemy->AddComponent(pursue);
	}

	
}
