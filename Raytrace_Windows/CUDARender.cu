#include"CUDARender.cuh"

#include"cuda.h"
#include<iostream>
#include<cufft.h>
#include"cublas_v2.h"
#include<stdio.h>
#include<stdlib.h>


bool CUDARender::Init(HDC dc)
{
	MainDC = dc;
	//OutImage = std::ofstream("image.png");
	//AllocConsole();

	Timer = time(NULL);

	return true;
}

bool CUDARender::Update()
{
	if (RenderDone)
		return false;

	Vector3 LowLeftCorner(-2.0f, -1.5f, -1.0f);
	Hittable* List[5];
	Camera Cam(Vector3(-2, 2, 1), Vector3(0, 0, -1), Vector3(0, 1, 0), 60, ASPECTRATIO);
	float R = cos(M_PI / 4);

	List[0] = new Sphere(Vector3(0, 0, -1), 0.5f, new Lambertian(Vector3(0.1f, 0.2f, 0.5f)));
	List[1] = new Sphere(Vector3(0, -100.5f, -1), 100.0f, new Lambertian(Vector3(0.8f, 0.8f, 0.0f)));
	List[2] = new Sphere(Vector3(1, 0, -1), 0.5f, new Metal(Vector3(0.8f, 0.6f, 0.2f), 0.3f));
	List[3] = new Sphere(Vector3(-1, 0, -1), 0.5f, new Dielectric(1.5f));
	List[4] = new Sphere(Vector3(-1, 0, -1), -0.45f, new Dielectric(1.5f));
	Hittable* World = new HittableList(List, 5);


	// 수직과 수평 벡터의 비율은 원하는 뷰포트 비율로 설정한다.
	// 나의 경우 (800, 600) 이므로 4:3 비율로 정하였다.
	Vector3 Horizontal(4.0f, 0.0f, 0.0f);
	Vector3 Vertical(0.0f, 3.0f, 0.0f);
	Vector3 Origin(0.0f, 0.0f, 0.0f);

	//OutImage << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			Vector3 color(0.0f, 0.0f, 0.0f);

			for (int s = 0; s < SAMPLE; s++)
			{
				float u = float(x + random_double()) / float(WIDTH);
				float v = float(y + random_double()) / float(HEIGHT);

				Ray ray = Cam.GetRay(u, v);

				color += Color(ray, World, 0);
			}

			color /= float(SAMPLE);
			color = Vector3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2]));

			int ir = int(255.99*color[0]);
			int ig = int(255.99*color[1]);
			int ib = int(255.99*color[2]);

			//	OutImage << ir << " " << ig << " " << ib << "\n";

			ScreenColors[y][x] = RGB(ir, ig, ib);
		}
	}

	ElapsedTime = (double)(time(NULL) - Timer);

	//OutImage.close();

	return true;
}

bool CUDARender::Render()
{

	if (RenderDone)
		return false;


	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{

			SetPixel(MainDC, x, y, ScreenColors[HEIGHT - y][x]);

		}
	}

	//wchar_t Buffer[256];
	//wsprintf(Buffer, L"%f", ElapsedTime);
	//TextOutW(MainDC, 0, 0, Buffer, 1);
	//std::cout << ElapsedTime << std::endl;
	printf("%f", ElapsedTime);

	RenderDone = true;

	return true;
}

bool CUDARender::Release()
{
	return true;
}

Vector3 CUDARender::Color(const Ray & ray, Hittable * World, int depth)
{
	HitRecord rec;

	if (World->hit(ray, 0.001f, FLT_MAX, rec))
	{
		Ray scattered;
		Vector3 attenuation;

		if (depth < 50 && rec.matptr->Scatter(ray, rec, attenuation, scattered))
			return attenuation * Color(scattered, World, depth + 1);
		else
			return Vector3(0, 0, 0);
		Vector3 Target = rec.p + rec.normal + RandomInUnitSphere();
		return 0.5f* Color(Ray(rec.p, Target - rec.p), World, 0);
	}
	else
	{
		Vector3 Direction = unit_vector(ray.Direction());
		float t = 0.5f * (Direction.y() + 1.0f);
		return (1.0f - t) * Vector3(1.0f, 1.0f, 1.0f) + t * Vector3(0.5f, 0.7f, 1.0f);
	}
}

float CUDARender::HitSphere(const Vector3 & center, float radius, const Ray & ray)
{
	Vector3 oc = ray.Origin() - center;

	float a = dot(ray.Direction(), ray.Direction());
	float b = 2.0f * dot(oc, ray.Direction());
	float c = dot(oc, oc) - radius * radius;

	float discriminant = b * b - 4 * a*c;

	if (discriminant < 0)
		return -1.0;

	else
		return (-b - sqrt(discriminant)) / (2.0*a);
}

CUDARender::CUDARender()
{
}

CUDARender::~CUDARender()
{
}
