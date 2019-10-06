#pragma once
#ifndef MATERIALH
#define MATERIALH

#include"Hit.h"
#include"3DMath.h"
#include"Random.h"

Vector3 RandomInUnitSphere();
Vector3 Reflect(const Vector3& v, const Vector3& n);
bool Refract(const Vector3& v, const Vector3&, float niovernt, Vector3& refracted);
float Schlick(float cosine, float ref_idx);

class Material
{
public:
	virtual bool Scatter(const Ray& rayin, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material 
{
private:
	Vector3 Albedo;
public:
	Lambertian(const Vector3& a) : Albedo(a) {}
	virtual bool Scatter(const Ray& rayin, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const;
};

class Metal : public Material
{
private:
	Vector3 Albedo;
	float fuzz;
public:
	Metal(const Vector3& a, float f) : Albedo(a) {
		if (f < 1) fuzz = f; else fuzz = 1;
	}
	virtual bool Scatter(const Ray& rayin, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const;

};

class Dielectric : public Material
{
private:

	float RefIdx;

public:
	virtual bool Scatter(const Ray& rayin, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const;

	Dielectric(float ri) : RefIdx(ri) {}

};


#endif