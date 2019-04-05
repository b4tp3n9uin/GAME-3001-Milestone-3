#pragma once
#include <list>
#include <iostream>
#include "SimpleEvent.h"
#include "Event.h"

class Component;
class Transform;
class Game;
class Scene;
//template <class T> class EventListener;
//template <class T> class Event;
class Collision;
class Collider;
class Rigidbody;
class GameObject
{
public:
	GameObject();
	GameObject(Game* _game, std::string name = "", float x = 0, float y = 0, float _angle = 0, float xScale = 1, float yScale = 1);
	GameObject(const GameObject &gameObject);
	~GameObject();
	void AddComponent(Component* component);
	template<class T> T* GetComponent();
	template<class T> std::list<T*> GetComponents();
	template<class T> void RemoveComponent();
	template<class T> void RemoveComponents();
	void Awake();
	void Update();
	void FixedUpdate();
	void Cleanup();
	std::string name;
	Transform* transform;
	inline void SetActive(bool toggle) { active = toggle; }
	inline bool isActive() { return active; }
	inline const Scene* const GetScene() { return scene; }
	inline const Game* const GetGame() { return game; }

	Event<GameObject*> OnAwake;	

	//Physics
	Rigidbody* rigidbody;
	Event<Rigidbody*> OnAddRigidbody;
	//Event<Rigidbody*> OnRemoveRigidbody;
	Event<Collision> OnCollisionEnter;
	Event<Collision> OnCollisionExit;
	Event<Collider*> OnTriggerEnter;
	Event<Collider*> OnTriggerExit;
	//std::shared_ptr<EventListener<Rigidbody*>> OnMyRigidbodyRemoved = std::make_shared<EventListener<Rigidbody*>>(std::bind(&SearchAndSetNewRigidBody, this));
private:
	friend class Rigidbody;
	friend class Transform;
	Rigidbody* SearchForNewRigidBody();
	void AddRigidbody(Rigidbody* _rigidbody);
	void RemoveRigidbody();
	//void OnChangeParent();
private:
	std::list<Component*> components;
	Game* game = NULL;
	Scene* scene = NULL;
	bool active = true;
	friend class Scene;
	bool awoken = false;
};

template<class T> T* GameObject::GetComponent()
{
	//T* found = nullptr;
	for (Component* component : components)
	{
		T* found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			return found;
		}
	}
	std::cout << "Component not found";
	return NULL;
}

template<class T> std::list<T*> GameObject::GetComponents()
{
	std::list<T*> foundComponents;
	T* found = NULL;
	for (Component* component : components)
	{
		found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			foundComponents.push_back(found);
		}
	}
	return foundComponents;
}

template<class T> void GameObject::RemoveComponent()
{
	Component* found = NULL;
	for (Component* component : components)
	{
		found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			break;
		}		
	}
	components.remove(found);
	found->Cleanup();
	delete found;
	found = NULL;
	std::cout << "Component not found";
	return;
}

template<class T> void GameObject::RemoveComponents()
{
	std::list<Component*> foundList;
	Component* found = NULL;
	for (Component* component : components)
	{
		found = dynamic_cast<T*>(component);
		if (found != NULL)
		{
			foundList.push_back(found);
		}
	}
	for (Component* component : foundList)
	{
		components.remove(component);
		component->Cleanup();
		delete component;
		component = NULL;
	}
	
	std::cout << "Component not found";
	return;
}


