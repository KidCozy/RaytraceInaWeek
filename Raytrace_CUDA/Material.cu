#pragma once
#include"Material.cuh"


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

bool Refract(const Vector3 & v, const Vector3& n, float niovernt, Vector3 & refracted)
{
	Vector3 uv = unit_vector(v);
	float dt = dot(uv, n);
	float discriminant = 1.0f - niovernt * niovernt * (1 - dt * dt);

	if (discriminant > 0)
	{
		refracted = niovernt * (uv - n * dt) - n * sqrt(discriminant);
		return true;
	}
	else
		return false;
}

float Schlick(float cosine, float ref_idx)
{
	float r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;

	return r0 + (1 - r0)*pow((1 - cosine), 5);
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

bool Dielectric::Scatter(const Ray & rayin, const HitRecord & rec, Vector3 & attenuation, Ray & scattered) const
{
	float NioverNt;
	Vector3 OutwardNormal;
	Vector3 Reflected = Reflect(rayin.Direction(), rec.normal);
	Vector3 Refracted;

	float ReflectProb;
	float Cosine;

	attenuation = Vector3(1.0f, 1.0f, 1.0f);

	if (dot(rayin.Direction(), rec.normal) > 0)
	{
		OutwardNormal = -rec.normal;
		NioverNt = RefIdx;
		Cosine = RefIdx * dot(rayin.Direction(), rec.normal) / rayin.Direction().legnth();
		Cosine = sqrt(1 - RefIdx * RefIdx*(1 - Cosine * Cosine));
	}
	else
	{
		OutwardNormal = rec.normal;
		NioverNt = 1.0f / RefIdx;

		Cosine = -dot(rayin.Direction(), rec.normal) / rayin.Direction().legnth();

	}

	if (Refract(rayin.Direction(), OutwardNormal, NioverNt, Refracted))
	{
		ReflectProb = Schlick(Cosine, RefIdx);
	}
	else
	{
		ReflectProb = 1.0f;
	}

	if (random_double() < ReflectProb)
	{
		scattered = Ray(rec.p, Reflected);
	}
	else
	{
		scattered = Ray(rec.p, Refracted);
	}

	return true;
}
