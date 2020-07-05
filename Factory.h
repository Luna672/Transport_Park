#pragma once

class Vehicle;
// factory
class Factory
{
public:
	// Vehicle creation function (each factory redefines this function for its type)
	virtual Vehicle* create() = 0;
};