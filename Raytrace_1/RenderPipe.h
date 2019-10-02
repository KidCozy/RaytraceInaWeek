#pragma once
#include"Material.h"
#include"HittableList.h"


#include"Sphere.h"
#include"Camera.h"

#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#define WIDTH 800
#define HEIGHT 600
#define RATIO WIDTH/HEIGHT
#define SAMPLE 100
class RenderPipe
{
private:
	HDC MainDC;
	COLORREF ScreenColors[HEIGHT][WIDTH];
	std::ofstream OutImage;
	time_t Timer;
	double ElapsedTime;

public:
	bool RenderDone = false;

public:

	bool Init(HDC dc);
	bool Update();
	bool Render();
	bool Release();

	Vector3 Color(const Ray& ray, Hittable *World, int depth);
	float HitSphere(const Vector3& center, float radius, const Ray& ray);

	RenderPipe();
	~RenderPipe();
};