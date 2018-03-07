#pragma once

#include <DxLib.h>
#include "Map.h"

class World {
public:
	World(char name[20], Map* map);

	Map* getMap();

private:
	char name[20];
	Map* map;
};
