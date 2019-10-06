#pragma once
#include "Hit.cuh"
class Sphere :
	public Hittable
{
private:
	Vector3 Center;
	float Radius;
	Material* matptr;
public:

	Sphere();
	Sphere(Vector3 cen, float r, Material* mat) : Center(cen), Radius(r), matptr(mat) {};

	~Sphere();

	// hittable��(��) ���� ��ӵ�
	virtual bool hit(const Ray & r, float t_min, float t_max, HitRecord & rec) const;

};

