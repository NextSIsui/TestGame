#include "Map.h"



Map::Map(int sizeX, int sizeY, char* filename){
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->blocks.resize(sizeX * sizeY);

	LoadDivGraph(filename, 8, 8, 2, 32, 32, GHandle);
}

int Map::getSizeX() {
	return sizeX;
}

int Map::getSizeY() {
	return sizeY;
}

vector<vector<int>> Map::getBlocks() {
	return blocks;
}

void Map::setBlocks(vector<vector<int>> blocks) {
	this->blocks = blocks;
}

void Map::drawOwn(Camera* camera) {
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			DrawGraph(j*32 - camera->getX(), i*32 - camera->getY(), GHandle[blocks[i][j]], true);
		}
	}
	
}

