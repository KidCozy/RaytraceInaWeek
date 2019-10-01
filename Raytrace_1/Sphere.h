#pragma once
#include "Hit.h"
class Sphere :
	public Hittable
{
private:
	Vector3 Center;
	float Radius;
public:

	Sphere();
	Sphere(Vector3 cen, float r) : Center(cen), Radius(r) {};

	~Sphere();

	// hittable을(를) 통해 상속됨
	virtual bool hit(const Ray & r, float t_min, float t_max, HitRecord & rec) const;

};

