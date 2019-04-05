#include "SimpleEvent.h"

SimpleEvent::SimpleEvent()
{

}

SimpleEvent::~SimpleEvent()
{

}

void SimpleEvent::AddListener(std::shared_ptr<SimpleEventListener> listener)
{
	listeners.push_back(listener);
}

void SimpleEvent::RemoveListener(std::shared_ptr<SimpleEventListener> listener)
{
	listeners.remove(listener);
}

void SimpleEvent::NotifyHandlers()
{
	for (std::shared_ptr<SimpleEventListener> e : listeners)
	{
		if (e->IsNotNull())
		{
			e->Handle();
		}
		else
		{
			RemoveListener(e);
		}
	}
}

void SimpleEvent::operator()()
{
	NotifyHandlers();
}