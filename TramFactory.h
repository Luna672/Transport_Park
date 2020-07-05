#pragma once
#include "Factory.h"

class TramFactory : public Factory
{
public:
	Vehicle * create();
};