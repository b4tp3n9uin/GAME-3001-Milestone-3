#pragma once
#include <list>
#include <memory>
#include <functional>
#include "SimpleEventListener.h"

class SimpleEvent
{
public:

	SimpleEvent();

	~SimpleEvent();

	void AddListener(std::shared_ptr<SimpleEventListener> listener);

	void RemoveListener(std::shared_ptr<SimpleEventListener> listener);

	void operator()();

private:

	std::list<std::shared_ptr<SimpleEventListener>> listeners;

	void NotifyHandlers();
};

