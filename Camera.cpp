#include "Camera.h"

Camera::Camera(int x, int y)
{
	this->x = x;
	this->y = y;
}


Camera::~Camera()
{
}

int Camera::getX()
{
	return x;
}

int Camera::getY()
{
	return y;
}

void Camera::setX(int x)
{
	this->x = x;
}

void Camera::setY(int y)
{
	this->y = y;
}
