#pragma once
#include"Material.h"
#include"HittableList.h"


#include"Sphere.h"
#include"Camera.h"

#include<iostream>
#include<string>
#include<fstream>

#define WIDTH 800
#define HEIGHT 600
#define SAMPLE 1
class RenderPipe
{
private:
	HDC MainDC;
	COLORREF ScreenColors[HEIGHT][WIDTH];
	std::ofstream OutImage;


public:
	bool RenderDone = false;

public:

	bool Init(HDC dc);
	bool Update();
	bool Render();
	bool Release();

	Vector3 Color(const Ray& ray, Hittable *World);
	float HitSphere(const Vector3& center, float radius, const Ray& ray);

	RenderPipe();
	~RenderPipe();
};