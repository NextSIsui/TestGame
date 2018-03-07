#pragma once

#include <DxLib.h>
#include <string.h>
#include "Livingentity.h"
#include "Location.h"
#include "Camera.h"

class Player :
	public LivingEntity
{
public:
	Player(char *ss, Location* location, char *filename);

	char* getName();

	bool getIsWalking();

	void setIsWalking(bool b);

	void drawOwn(World* map, Camera* camera);

	void move(int vector, int magnitude);

private:
	char name[40];
	int GHandle[12];
	int animeFlame = 0;
	int animeDrawFlame = 0;
	bool isWalking;

};