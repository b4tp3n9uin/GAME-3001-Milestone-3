#pragma once
#include <list>
#include <memory>
#include <functional>
#include "EventListener.h"
//http://www.dannyb.me/posts/2014/02/creating_event_system_c++/

template <class T>
class Event
{
public:

	Event();

	~Event();

	void AddListener(std::shared_ptr<EventListener<T>> listener);

	void RemoveListener(std::shared_ptr<EventListener<T>> listener);

	void operator()(const T t);

private:

	std::list<std::shared_ptr<EventListener<T>>> listeners;

	void NotifyHandlers(const T t);
};

template <class T> Event<T>::Event()
{

}

template <class T> Event<T>::~Event()
{

}

template <class T> void Event<T>::AddListener(std::shared_ptr<EventListener<T>> listener)
{
	listeners.push_back(listener);
}

template <class T> void Event<T>::RemoveListener(std::shared_ptr<EventListener<T>> listener)
{
	listeners.remove(listener);
}

template <class T> void Event<T>::NotifyHandlers(const T t)
{
	for (std::shared_ptr<EventListener<T>> e : listeners)
	{
		if (e->IsNotNull())
		{
			e->Handle(t);
		}
		else
		{
			RemoveListener(e);
		}
	}
}

template <class T> void Event<T>::operator()(const T t)
{
	NotifyHandlers(t);
}



