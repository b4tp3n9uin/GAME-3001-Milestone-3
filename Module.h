#pragma once
class Module
{
public:
	Module();
	virtual ~Module();
	virtual void Start();
	virtual void Update();
	virtual void CleanUp();
};
