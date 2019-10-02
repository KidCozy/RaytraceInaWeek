#pragma once
#ifndef HITTABLEH
#define HITTABLEH

#include"Ray.h"

class Material;

struct HitRecord
{
	float t;
	Vector3 p;
	Vector3 normal;
	Material *matptr;
};

class Hittable 
{
public:
	virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const = 0;
};

#endif