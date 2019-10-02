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

Vector3 Reflect(const Vector3& v, const Vector3& n)
{
	return v - 2 * dot(v, n)*n;
}

bool Lambertian::Scatter(const Ray & rayin, const HitRecord & rec, Vector3 & attenuation, Ray & scattered) const
{
	Vector3 Target = rec.p + rec.normal + RandomInUnitSphere();
	scattered = Ray(rec.p, Target - rec.p);
	attenuation = Albedo;
	return true;
}

bool Metal::Scatter(const Ray & rayin, const HitRecord & rec, Vector3 & attenuation, Ray & scattered) const
{
	Vector3 Reflected = Reflect(unit_vector(rayin.Direction()), rec.normal);
	scattered = Ray(rec.p, Reflected);
	attenuation = Albedo;

	return (dot(scattered.Direction(), rec.normal) > 0);
}
