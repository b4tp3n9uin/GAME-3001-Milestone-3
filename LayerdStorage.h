#pragma once
#include <iostream>
#include <vector>
#include <list>

template<class T>
class LayerdStorage
{
public:
	LayerdStorage(uint8_t _numberOfLayers = 0);
	~LayerdStorage();

	void Add(T* renderer);
	void Remove(T* renderer);
	std::vector<std::list<T*>> container;

private:
	uint8_t numberOfLayers;

};


template<class T> LayerdStorage<T>::LayerdStorage(uint8_t _numberOfLayers)
{
	numberOfLayers = _numberOfLayers;
	for (int i = 0; i < numberOfLayers; i++)
	{
		container.push_back(std::list<T*>());
	}
}


template<class T>LayerdStorage<T>::~LayerdStorage()
{
}

template<class T> void LayerdStorage<T>::Add(T* t)
{
	if (t->GetLayer() >= numberOfLayers)
	{
		//std::cout << "Render layer for GameObject " << (std::string)t->gameObject->name << " is " << t->GetLayer() << " which does not exist!";
		return;
	}
	container.at(t->GetLayer()).push_back(t);
}

template<class T> void LayerdStorage<T>::Remove(T* t)
{
	if (t->GetLayer() >= numberOfLayers)
	{
		//std::cout << "Render layer for GameObject " << t->gameObject->name << " is " << t->GetLayer() << " which does not exist!";
		return;
	}
	container.at(t->GetLayer()).remove(t);
}

