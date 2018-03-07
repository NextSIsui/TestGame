#include "World.h"

World::World(char name[20], Map* map){

	strcpy_s(this->name, name);
	this->map = map;
}

Map* World::getMap() {
	return map;
}