#pragma once
#include"Ray.h"
class Camera
{
private:
	Vector3 Origin;
	Vector3 LowLeftCorner;
	Vector3 Horizontal;
	Vector3 Vertical;

public:
	Camera();
	~Camera();
	Ray GetRay(float u, float v) { return Ray(Origin, LowLeftCorner + u * Horizontal + v * Vertical - Origin); }
};

