#include "Location.h"

Location::Location(World* world, int posX, int posY) {
		this->world = world;
		this->posX = posX;
		this->posY = posY;
	}

World* Location::getWorld() {
	return world;
}

int Location::getX() {
	return posX;
}

int Location::getY() {
	return posY;
}

int Location::getVector() {
	return vector;
}

void Location::setX(int posX){
	this->posX = posX;
}

void Location::setY(int posY){
	this->posY = posY;
}

void Location::setVector(int vector){
	this->vector = vector;
}


