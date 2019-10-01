#pragma once
#ifndef HITTABLELISTH
#define HITTABLELISTH
#include"Hit.h"
class HittableList : public Hittable
{
private:
	Hittable** List;
	int ListSize;
public:
	HittableList();
	HittableList(Hittable **l, int n) { List = l; ListSize = n; }
	~HittableList();

	// Hittable��(��) ���� ��ӵ�
	virtual bool hit(const Ray & r, float t_min, float t_max, HitRecord & rec) const;
};

#endif