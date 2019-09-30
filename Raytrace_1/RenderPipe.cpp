#include "stdafx.h"
#include "RenderPipe.h"


bool RenderPipe::Init(HDC dc)
{
	MainDC = dc;

	return true;
}

bool RenderPipe::Update()
{
	if (RenderDone)
		return false;

	Vector3 LowLeftCorner(-2.0f, -1.0f, -1.0f);
	Vector3 Horizontal(4.0f, 0.0f, 0.0f);
	Vector3 Vertical(0.0f, 3.0f, 0.0f);
	Vector3 Origin(0.0f, 0.0f, 0.0f);

	for (int y = HEIGHT-1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			float u = float(x) / float(WIDTH);
			float v = float(y) / float(HEIGHT);

			Ray ray(Origin, LowLeftCorner + u * Horizontal + v * Vertical);
			Vector3 color = Color(ray);

			int ir = int(255.99*color[0]);
			int ig = int(255.99*color[1]);
			int ib = int(255.99*color[2]);

			ScreenColors[y][x] = RGB(ir, ig, ib);
		}
	}

	return true;
}

bool RenderPipe::Render()
{
	wchar_t Buffer[256];
	int x = ScreenColors[0][1];
	wsprintf(Buffer, L"%d", x);
	TextOut(MainDC, 0, 0, Buffer, 2);

	if (RenderDone)
		return false;



	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			SetPixel(MainDC, x, y, ScreenColors[y][x]);
			
		}
	}
	

	RenderDone = true;

	return true;
}

bool RenderPipe::Release()
{
	return true;
}

bool RenderPipe::HitSphere(const Vector3 & center, float radius, const Ray & ray)
{
	Vector3 oc = ray.Origin() - center;

	float a = dot(ray.Direction(), ray.Direction());
	float b = 2.0f * dot(oc, ray.Direction());
	float c = dot(oc, oc) - radius * radius;

	float discriminant = b * b - 4 * a*c;

	return (discriminant > 0);
}

RenderPipe::RenderPipe()
{
}


RenderPipe::~RenderPipe()
{
}
