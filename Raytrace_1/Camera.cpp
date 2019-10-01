#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
	LowLeftCorner = Vector3(-2.0f, -1.5f, -1.0f);
	Horizontal = Vector3(4.0f, 0.0f, 0.0f);
	Vertical = Vector3(0.0f, 3.0f, 0.0f);
	Origin = Vector3(0.0f, 0.0f, 0.0f);

}



Camera::~Camera()
{
}
