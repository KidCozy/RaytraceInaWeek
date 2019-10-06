#include "stdafx.h"
#include "Camera.h"


Camera::Camera(Vector3 Eye, Vector3 At, Vector3 Up, float vFov, float Aspect)
{
	Vector3 u, v, w;
	float theta = vFov * M_PI / 180;
	float halfheight = tan(theta / 2);
	float halfwidth = Aspect * halfheight;

	w = unit_vector(Eye - At);
	u = unit_vector(cross(Up, w));
	v = cross(w, u);
	Origin = Eye;

	LowLeftCorner = Origin - halfwidth * u - halfheight * v - w;
	Horizontal = 2 * halfwidth*u;
	Vertical = 2 * halfheight*v;

}



Camera::~Camera()
{
}
