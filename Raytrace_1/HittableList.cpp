#include "stdafx.h"
#include "HittableList.h"


HittableList::HittableList()
{
}


HittableList::~HittableList()
{
}

bool HittableList::hit(const Ray & r, float t_min, float t_max, HitRecord & rec) const
{
	HitRecord temp_rec;
	bool HitAnything = false;
	double ClosestSoFar = t_max;
	
	for (int i = 0; i < ListSize; i++)
	{
		if (List[i]->hit(r, t_min, ClosestSoFar, temp_rec))
		{
			HitAnything = true;
			ClosestSoFar = temp_rec.t;
			rec = temp_rec;
		}
	}
	return HitAnything;
}
