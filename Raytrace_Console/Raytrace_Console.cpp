// Raytrace_Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<fstream>
int main()
{
	int nx = 200;
	int ny = 100;
	
	
	std::ofstream out("image.txt");

	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	out << "P3\n" << nx << " " << ny << "\n255\n";

	for (int j = ny-1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			std::string str;
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2f;

			int ir = int(255.99*r);
			int ig = int(255.99*g);
			int ib = int(255.99*b);

			std::cout << ir << " " << ig << " " << ib << "\n";
			
			out << ir << " " << ig << " " << ib << "\n";

		}
	}

	out.close();
}