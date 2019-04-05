#include "CameraFollow.h"
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"


CameraFollow::CameraFollow() {
}


CameraFollow::~CameraFollow() {
}

void CameraFollow::Update() {
	Camera::x = (gameObject->transform->GetAbsolutePosition().x) - (Camera::width / 2);
	Camera::y = (gameObject->transform->GetAbsolutePosition().y) - (Camera::height / 2);
}