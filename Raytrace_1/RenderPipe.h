#pragma once
#include"Ray.h"
#include<iostream>
#include<string>
#define WIDTH 800
#define HEIGHT 600

class RenderPipe
{
private:
	HDC MainDC;
	COLORREF ScreenColors[HEIGHT][WIDTH];

public:
	bool RenderDone = false;

public:

	bool Init(HDC dc);
	bool Update();
	bool Render();
	bool Release();

	Vector3 Color(const Ray& ray)
	{
		if (HitSphere(Vector3(0, 0, -1), 0.5, ray))
			return Vector3(1, 0, 0);
		Vector3 Direction = unit_vector(ray.Direction());
		float t = 0.5*(Direction.y() + 1.0f);
		return (1.0f - t)*Vector3(1.0f, 1.0f, 1.0f) + t * Vector3(0.5f, 0.7f, 1.0f);
	}

	bool HitSphere(const Vector3& center, float radius, const Ray& ray);

	RenderPipe();
	~RenderPipe();
};

