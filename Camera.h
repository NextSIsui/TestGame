#pragma once

class Camera
{
public:
	Camera(int x, int y);
	~Camera();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

private:
	int x;
	int y;
};

