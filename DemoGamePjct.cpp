#include "DemoGamePjct.h"
#include "Scene1.h"
#include "Bullet.h"
#include "Enemy.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Collision.h"

DemoGamePjct::DemoGamePjct()
{
}


DemoGamePjct::~DemoGamePjct()
{
}

void DemoGamePjct::Awake()
{
	AddPrefab("Enemy", std::bind(&DemoGamePjct::EnemyPrebab, this, std::placeholders::_1));
	AddPrefab("Bullet", std::bind(&DemoGamePjct::BulletPrebab, this, std::placeholders::_1));
}

void DemoGamePjct::Setup()
{
	SetScene(new Scene1());
}

void DemoGamePjct::BackGround()
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Test window", 1280, 720, 1280, 720, NULL);
	if (window == NULL)
	{
		std::cout << ("could not create window: %s/n", SDL_GetError());
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	int x = 0, y = 0;
	SDL_Surface  *screen;
	SDL_Surface *background = SDL_LoadBMP("Assets/snow.jpg");
	if (background == NULL)
	{
		SDL_ShowSimpleMessageBox(0, "Background init error", SDL_GetError(), window);
	}

	if (renderer == NULL)
	{
		SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window);
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, background);
	if (texture == NULL)
	{
		SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), window);
	}
}

void DemoGamePjct::EnemyPrebab(GameObject* enemy)
{
	enemy->name = "Enemy";
	enemy->AddComponent(new SpriteRenderer("Assets/Polar_Bear.png"));
	enemy->AddComponent(new Enemy());
	enemy->transform->SetAbsoluteScale(Vector2(0.5f, 0.5f));

	Rigidbody* enemyRb = new Rigidbody();
	enemyRb->SetBodyType(Rigidbody::dynamicBody);
	enemy->AddComponent(enemyRb);
	BoxCollider* enemyCol = new BoxCollider();
	enemy->AddComponent(enemyCol);

	// Collider size and layer
	enemyCol->SetDimension(Vector2(70, 70));
	enemyCol->SetCategory(physics->Layer_3);
	enemyCol->SetCollisionMask(~physics->Layer_3);

	//enemyGraphic->OnCollisionEnter
}

void DemoGamePjct::BulletPrebab(GameObject* bullet) {
	// Setup bullet
	bullet->name = "Bullet";
	bullet->AddComponent(new SpriteRenderer("Assets/bullet.png"));
	bullet->AddComponent(new Bullet());
	bullet->transform->SetAbsoluteScale(Vector2(0.1f, 0.1f));

	// // Set rigidbody
	 Rigidbody* rb = new Rigidbody();
	 rb -> SetBodyType(Rigidbody::dynamicBody);
	 bullet -> AddComponent(rb);
	 rb -> SetBullet(true);
	
	 // Set Collider
	 BoxCollider* col = new BoxCollider();
	 bullet -> AddComponent(col);
	
	 col -> SetDimension(Vector2(10,10));
	 col -> SetTrigger(true);

}

void DemoGamePjct::WallPrebab(GameObject * wall)
{
	// Set Wall
	wall->name = "Wall";

	// Graphics
	SpriteRenderer* wallRenderer = new SpriteRenderer(new Sprite("Assets/stones_wall.png"), 1);
	wall->AddComponent(wallRenderer);
	wall->transform->SetRelativeScale(Vector2(0.15f, 0.2f));

	// RigidBody
	Rigidbody* rb = new Rigidbody();
	rb->SetBodyType(Rigidbody::staticBody);
	wall->AddComponent(rb);

	// Collider
	BoxCollider* col = new BoxCollider();
	wall->AddComponent(col);

	col->SetCategory(physics->Layer_1);
	col->SetDimension(Vector2(800, 624));
}