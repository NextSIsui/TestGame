#pragma once
#include <DxLib.h>
#include <vector>

#include "Camera.h"

using namespace std;

class Map
{
public:
	Map(int sizeX, int sizeY, char* filename);

	int getSizeX();
	int getSizeY();

	vector<vector<int>> getBlocks();

	void setBlocks(vector<vector<int>> blocks);

	void drawOwn(Camera* camera);

private:
	int sizeX, sizeY;
	int GHandle[16];
	vector< vector<int> > blocks;
};

