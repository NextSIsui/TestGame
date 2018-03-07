#include "Entity.h"



Entity::Entity(Location* location)
{
	this->location = location;
}


Entity::~Entity()
{
}

Location * Entity::getLocation()
{
	return location;
}