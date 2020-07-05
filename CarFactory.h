#pragma once
#include "Factory.h"

class CarFactory : public Factory
{
public:
	Vehicle * create();
};