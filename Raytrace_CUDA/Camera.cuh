#pragma once
#include"Ray.cuh"
class Camera
{
private:
	Vector3 Origin;
	Vector3 LowLeftCorner;
	Vector3 Horizontal;
	Vector3 Vertical;

public:
	Camera(Vector3 Eye, Vector3 At, Vector3 Up, float vFov, float Aspect);
	~Camera();
	Ray GetRay(float u, float v) { return Ray(Origin, LowLeftCorner + u * Horizontal + v * Vertical - Origin); }
};

