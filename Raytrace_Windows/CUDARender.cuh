#pragma once
#include<Windows.h>
#include"Material.cuh"
#include"HittableList.cuh"
#include"Sphere.cuh"
#include"Camera.cuh"
#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include<cuda_runtime.h>

#define WIDTH 800
#define HEIGHT 600
#define ASPECTRATIO WIDTH/HEIGHT
#define SAMPLE 1

#ifdef __cplusplus
extern "C" {
#endif
	class CUDARender
	{
	private:
		HDC MainDC;

		COLORREF ScreenColors[HEIGHT][WIDTH];
	//	std::ofstream OutImage;
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

		CUDARender();
		~CUDARender();
	};

#ifdef __cplusplus
}
#endif

//class CUDARender
//{
//	private:
//		HDC MainDC;
//		COLORREF ScreenColors[HEIGHT][WIDTH];
//		std::ofstream OutImage;
//		time_t Timer;
//		double ElapsedTime;
//	public:
//		bool RenderDone = false;
//	public:
//		bool Init(HDC dc);
//		bool Update();
//		bool Render();
//		bool Release();
//
//		Vector3 Color(const Ray& ray, Hittable *World, int depth);
//		float HitSphere(const Vector3& center, float radius, const Ray& ray);
//
//		CUDARender(void);
//		~CUDARender(void);
//};

