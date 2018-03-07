#include "Player.h"
#include <string.h>

Player::Player(char *ss, Location* location, char *filename) : LivingEntity(location)
{

	strcpy_s(name, ss);
	LoadDivGraph(filename, 12, 3, 4, 20, 28, GHandle);
}

char* Player::getName() {
	return name;
}

bool Player::getIsWalking() {
	return isWalking;
}

void Player::setIsWalking(bool b){
	isWalking = b;
}

void Player::drawOwn(World* world, Camera* camera){
	if (location->getWorld() != world) return;

	int x = location->getX();
	int y = location->getY();

	int fixedX = x - camera->getX() - 20;
	int fixedY = y - camera->getY() - 28*2;

	if (!isWalking)
		DrawExtendGraph(fixedX, fixedY, fixedX + 20 * 2, fixedY + 28 * 2, GHandle[location->getVector() * 3 + 1], true);
	else {
		if ((animeFlame++) % 15 == 0)
			animeDrawFlame++;

		switch ((animeDrawFlame) % 4) {
	
		case 0:
			DrawExtendGraph(fixedX, fixedY, fixedX + 20 * 2, fixedY + 28 * 2, GHandle[location->getVector() * 3 + 0], true);
			break;
	
		case 1:
		case 3:
			DrawExtendGraph(fixedX, fixedY, fixedX + 20 * 2, fixedY + 28 * 2, GHandle[location->getVector() * 3 + 1], true);
			break;
	
		case 2:
			DrawExtendGraph(fixedX, fixedY, fixedX + 20 * 2, fixedY + 28 * 2, GHandle[location->getVector() * 3 + 2], true);
			break;
		}
	}


}

void Player::move(int vector, int magnitude) {

	switch (vector) {
		case 3:
			location->setY(location->getY() - magnitude);
			location->setVector(vector);
			setIsWalking(true);
			break;
	
		case 0:
			location->setY(location->getY() + magnitude);
			location->setVector(vector);
			setIsWalking(true);
			break;
	
		case 2:
			location->setX(location->getX() + magnitude);
			location->setVector(vector);
			setIsWalking(true);
			break;
	
		case 1:
			location->setX(location->getX() - magnitude);
			location->setVector(vector);
			setIsWalking(true);
			break;
	
		default:
			setIsWalking(false);
	
	}
}
