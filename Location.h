#pragma once

#include <DxLib.h>
#include "World.h"

class Location {

public:
	Location(World* world, int posX, int posY);

	World* getWorld();

	int getX();
	int getY();
	int getVector();

	void setX(int posX);
	void setY(int posY);
	void setVector(int vector);

private:
	World* world;
	int posX;
	int posY;
	int vector;

};

