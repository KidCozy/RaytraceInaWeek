#pragma once
#include"stdafx.h"
#include"Material.h"


Vector3 RandomInUnitSphere()
{
	Vector3 p;

	do
	{
		p = 2.0f * Vector3(random_double(), random_double(), random_double()) - Vector3(1.0f, 1.0f, 1.0f);
	} while (p.squared_length() >= 1.0f);

	return p;
}