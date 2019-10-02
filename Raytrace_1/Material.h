#pragma once
#ifndef MATERIALH
#define MATERIALH

#include"Hit.h"
#include"3DMath.h"
#include"Random.h"

Vector3 RandomInUnitSphere();
Vector3 Reflect(const Vector3& v, const Vector3& n);
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
public:
	Metal(const Vector3& a) : Albedo(a) {}
	virtual bool Scatter(const Ray& rayin, const HitRecord& rec, Vector3& attenuation, Ray& scattered) const;

};


#endif