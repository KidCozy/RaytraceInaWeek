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
#define BYTES_PER_PIXEL 3 // RGB
#define BITS_PER_PIXEL 24

#ifdef __cplusplus
extern "C" {
#endif
	class CUDARender
	{
	private:
		HDC MainDC, MemoryDC;
		BYTE* ScreenBits;
		HWND hwnd;

		VColor ScreenColors[HEIGHT][WIDTH];

		HBITMAP DIBitmap;
		HBITMAP OldDIBitmap;

		VColor CurrentColor;

	//	std::ofstream OutImage;
		UINT BytesPerScanline = (WIDTH * BYTES_PER_PIXEL + 3) & ~3;
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

		void SetHwndPointer(HWND& hWnd) { hwnd = hWnd; }

		void Clear(VColor ClearColor);
		void SwapBuffer();

		void SetPixel(UINT x, UINT y);
		bool IsInScreen(UINT x, UINT y);

		CUDARender();
		~CUDARender();
	};

#ifdef __cplusplus
}
#endif


/***********obsolete**********/
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

