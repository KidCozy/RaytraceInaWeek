#pragma once
#include<iostream>
#include<math.h>
#include<stdlib.h>

struct Vector2
{
	int x;
	int y;

	Vector2(int _x, int _y) { x = _x; y = _y; }
};

struct Vector3
{
public:
	Vector3() {}
	Vector3(float x, float y, float z) { e[0] = x; e[1] = y; e[2] = z; }

	inline float x() const { return _0; }
	inline float y() const { return _1; }
	inline float z() const { return _2; }
	inline float r() const { return _0; }
	inline float g() const { return _1; }
	inline float b() const { return _2; }

	inline const Vector3& operator+() const { return *this; }
	inline Vector3 operator-() const { return Vector3(-_0, -_1, -_2); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline Vector3& operator+=(const Vector3 &Vec2);
	inline Vector3& operator-=(const Vector3 &Vec2);
	inline Vector3& operator*=(const Vector3 &Vec2);
	inline Vector3& operator/=(const Vector3 &Vec2);
	inline Vector3& operator*=(const float s);
	inline Vector3& operator/=(const float s);

	inline float legnth() const { return sqrt(_0*_0 + _1 * _1 + _2 * _2); }
	inline float squared_length() const { return _0 * _0 + _1 * _1 + _2 * _2; }
	inline void make_unit_vector();

	union {
		float e[3];
		struct {
			float _0;
			float _1;
			float _2;
		};
	};



};


inline std::istream& operator>>(std::istream &is, Vector3 &v)
{
	is >> v._0 >> v._1 >> v._2;
	return is;
}

inline std::ostream& operator<<(std::ostream &os, const Vector3 &v)
{
	os << v._0 << " " << v._1 << " " << v._2;
	return os;
}

inline Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1._0 + v2._0, v1._1 + v2._1, v1._2 + v2._2);
}

inline Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1._0 - v2._0, v1._1 - v2._1, v1._2 - v2._2);
}

inline Vector3 operator*(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1._0 * v2._0, v1._1 * v2._1, v1._2 * v2._2);
}

inline Vector3 operator*(float s, const Vector3 &v)
{
	return Vector3(s*v._0, s*v._1, s*v._2);
}

inline Vector3 operator*(const Vector3 &v, float s)
{
	return Vector3(s*v._0, s*v._1, s*v._2);
}

inline Vector3 operator/(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1._0 / v2._0, v1._1 / v2._1, v1._2 / v2._2);
}

inline Vector3 operator/(Vector3 v, float s)
{
	return Vector3(v._0 / s, v._1 / s, v._2 / s);
}

inline float dot(const Vector3 &v1, const Vector3 &v2)
{
	return v1._0 * v2._0 + v1._1 * v2._1 + v1._2 * v2._2;
}

inline Vector3 cross(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1._1 * v2._2 - v1._2 * v2._1,
		v1._2 * v2._0 - v1._0 * v2._2,
		v1._0*v2._1 - v1._1 * v2._0);
}

inline Vector3 & Vector3::operator+=(const Vector3 & Vec2)
{
	_0 += Vec2._0;
	_1 += Vec2._1;
	_2 += Vec2._2;
	return *this;
}

inline Vector3 & Vector3::operator-=(const Vector3 & Vec2)
{
	_0 -= Vec2._0;
	_1 -= Vec2._1;
	_2 -= Vec2._2;
	return *this;
}

inline Vector3 & Vector3::operator*=(const Vector3 & Vec2)
{
	_0 *= Vec2._0;
	_1 *= Vec2._1;
	_2 *= Vec2._2;
	return *this;
}

inline Vector3 & Vector3::operator/=(const Vector3 & Vec2)
{
	_0 /= Vec2._0;
	_1 /= Vec2._1;
	_2 /= Vec2._2;
	return *this;
}

inline Vector3 & Vector3::operator*=(const float s)
{
	_0 *= s;
	_1 *= s;
	_2 *= s;
	return *this;
}

inline Vector3 & Vector3::operator/=(const float s)
{
	float k = 1.0f / s;
	_0 *= k;
	_1 *= k;
	_2 *= k;
	return *this;
}

inline void Vector3::make_unit_vector()
{
	float k = 1.0f / sqrt(_0 * _0 + _1 * _1 + _2 * _2);
	_0 *= k;
	_1 *= k;
	_2 *= k;
}

inline Vector3 unit_vector(Vector3 v)
{
	return v / v.legnth();
}
