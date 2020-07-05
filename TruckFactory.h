#pragma once
#include "Factory.h"

class TruckFactory : public Factory
{
public:
	Vehicle * create();
};