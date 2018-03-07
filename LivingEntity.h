#pragma once
#include "Entity.h"
#include "Location.h"
class LivingEntity :
	public Entity
{
public:
	LivingEntity(Location* location);
	~LivingEntity();
};

