#pragma once
#include <iostream>
#include <functional>

class SimpleEventListener
{
public:
	using function = std::function<void()>;

private:
	function handler;

public:
	SimpleEventListener(const function &_handler);

	~SimpleEventListener();

	void Handle();
	void operator()();

	bool IsNotNull();
};

