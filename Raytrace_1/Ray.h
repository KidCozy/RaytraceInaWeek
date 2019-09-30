#pragma once

#ifndef RAYH
#define RAYH

#include"3DMath.h"
class Ray
{
public:

	Vector3 A;
	Vector3 B;

	Ray();
	Ray(const Vector3& a, const Vector3& b) { A = a; B = b; }
	Vector3 Origin() const { return A; }
	Vector3 Direction() const { return B; }
	Vector3 PointAtParameter(float t) const { return A + t * B; }
	~Ray();
};


#endif