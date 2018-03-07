#include <DxLib.h>
#include <vector>
#include "Player.h"
#include "Camera.h"

using namespace std;

//* プロトタイプ宣言 *//
void fixCamera(Camera* camera);
void drawScreen(Camera* camera);
int keyInput();

vector<Player*> players;
int lastCount = GetNowCount();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Map* map = new Map(20, 20, "mapChipBeta.png");
	World* world = new World("最初の村", map);
	Location* location = new Location(world,50, 50);
	Player* player = new Player("name", location, "Chara.png");
	Camera* camera = new Camera(0, 0);

	players.push_back(player);

	unsigned int Cr = GetColor(255, 255, 255);

	//マップ仮作成
	
	
	vector<vector<int>> blocks;
		blocks.push_back({ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 });
		blocks.push_back({ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 });
	
	map->setBlocks(blocks);
	


	while (ProcessMessage() != -1 && !ScreenFlip() && !ClearDrawScreen()) 
	{

		fixCamera(camera);

		drawScreen(camera);

		keyInput();

		//FPS制御
		WaitTimer((1000 / 60) - ((double)GetNowCount() - (double)lastCount));
	}

	delete map;
	delete world;
	delete location;
	delete player;
	delete camera;

	DxLib_End();
	return 0;
}

void fixCamera(Camera* camera) 
{
	int xr = players[0]->getLocation()->getX()-320;
	int yr = players[0]->getLocation()->getY()-240;

	int xl = players[0]->getLocation()->getX() + 320;
	int yl = players[0]->getLocation()->getY() + 240;

	if (xr > 0 && xl < players[0]->getLocation()->getWorld()->getMap()->getSizeX() * 32)
	{
		camera->setX(xr);
	}
	if (yr > 0 && yl < players[0]->getLocation()->getWorld()->getMap()->getSizeY() * 32) 
	{
		camera->setY(yr);
	}
	
}

void drawScreen(Camera* camera) 
{

	players[0]->getLocation()->getWorld()->getMap()->drawOwn(camera);

	for (int i = 0; i < players.size(); i++) 
	{
		players[i]->drawOwn(players[0]->getLocation()->getWorld(), camera);
	}

	DrawPixel(320, 240, (0, 0, 0));
}

int keyInput() 
{
	if (CheckHitKey(KEY_INPUT_UP)) 
	{
		players[0]->move(3, 2);
		return 3;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) 
	{
		players[0]->move(0, 2);
		return 0;
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)) 
	{
		players[0]->move(2, 2);
		return 2;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) 
	{
		players[0]->move(1, 2);
		return 1;
	}
	else 
	{
		players[0]->move(4, 0);
	}
}