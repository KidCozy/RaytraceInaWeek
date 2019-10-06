#include "Sphere.cuh"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray & r, float t_min, float t_max, HitRecord & rec) const
{
	Vector3 oc = r.Origin() - Center;
	float a = dot(r.Direction(), r.Direction());
	float b = dot(oc, r.Direction());
	float c = dot(oc, oc) - Radius * Radius;
	float discriminant = b * b - a * c;

	//std::cout << a << std::endl;

	if (discriminant > 0)
	{
		float temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.PointAtParameter(rec.t);
			rec.normal = (rec.p - Center) / Radius;
			rec.matptr = matptr;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.PointAtParameter(rec.t);
			rec.normal = (rec.p - Center) / Radius;
			rec.matptr = matptr;
			return true;
		}

	}

	return false;
}
