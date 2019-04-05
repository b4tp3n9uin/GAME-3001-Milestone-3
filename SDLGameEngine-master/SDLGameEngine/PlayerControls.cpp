#include "PlayerControls.h"
#include "Input.h"
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Time.h"
#include "Shoot.h"
#include <vector>
#include "Vector2.h"
using namespace std;

PlayerControls::PlayerControls() {

}


PlayerControls::~PlayerControls() {

}


void PlayerControls::Update() {





	// Create vector2 obj
	Vector2 direction;

	// Change x and y direction according to the key
	direction.x = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
	direction.y = Input::GetKey(SDLK_s) ? 1 : Input::GetKey(SDLK_w) ? -1 : 0;

	// Make the Vector2 vector single length (combine all director into one single direction);
	direction.Normalize();

	// Set player position
	gameObject->transform->SetAbsolutePositionDelta(direction * speed * Time::DeltaTime());

	// Calculate player angle in radiant
	float angle = atan2(direction.y, direction.x);

	// Change direction only when pressing buttons
	if (direction.Length() >= 0.01f) {
		// Convert player angle to degree and set angle
		gameObject->transform->SetAbsoluteAngle(angle * 180.0f / M_PI);
	}

	if (Input::GetKeyUp(SDLK_SPACE)) {
		Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() + 15 * gameObject->transform->Up(), gameObject->transform->GetAbsoluteAngle() + 270);
	}
	// Quit on Escape button
	if (Input::GetKey(SDLK_ESCAPE)) {
		Game::quit = true;
	}



}