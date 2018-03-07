#pragma once
#include "Location.h"
class Entity
{
public:
	Entity(Location * location);
	~Entity();

public:	Location* getLocation();

protected:
	Location* location;
};

