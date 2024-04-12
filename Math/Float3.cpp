
#include "Float3.h"

namespace qhy
{
	Float3::Float3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Float3::Float3(float q)
	{
		x = y = z = q;
	}

	float& Float3::operator[](int i)
	{
		return c[i];
	}

	Float3& Float3::operator+=(Float3 const& q)
	{
		x += q.x;
		y += q.y;
		z += q.z;
		return *this;
	}
	Float3& Float3::operator-=(Float3 const& q)
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		return *this;
	}
	Float3& Float3::operator*=(Float3 const& q)
	{
		x *= q.x;
		y *= q.y;
		z *= q.z;
		return *this;
	}
	//Float3& Float3::operator*=(Float3X4 const& q);
	Float3& Float3::operator*=(float q)
	{
		x *= q;
		y *= q;
		z *= q;
		return *this;

	}
	Float3& Float3::operator/=(Float3 const& q)
	{
		x /= q.x;
		y /= q.y;
		z /= q.z;
		return *this;
	}
	Float3& Float3::operator/=(float q)
	{
		x /= q;
		y /= q;
		z /= q;
		return *this;
	}


	Float3 Float3::operator+(Float3 const& q)
	{
		return Float3(x + q.x, y + q.y, z + q.z);
	}
	Float3 Float3::operator-(Float3 const& q)
	{
		return Float3(x - q.x, y - q.y, z - q.z);
	}
	Float3 Float3::operator*(Float3 const& q)
	{
		return Float3(x * q.x, y * q.y, z * q.z);
	}
	//Float3 Float3::operator*(Float3X4 const& q);
	Float3 Float3::operator*(float q)
	{
		return Float3(x * q, y * q, z * q);
	}
	Float3 Float3::operator/(Float3 const& q)
	{
		return Float3(x / q.x, y / q.y, z / q.z);
	}
	Float3 Float3::operator/(float q)
	{
		return Float3(x / q, y / q, z / q);
	}

	float Float3::Sum()
	{
		return x + y + z;
	}
	float Float3::Sum(Float3& q)
	{
		return q.Sum();
	}
	float Float3::Length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	void Float3::Normalize()
	{
		float len = Length();
		x /= len;
		y /= len;
		z /= len;
	}

	void Float3::Zeroing()
	{
		x = y = z = 0.0f;
	}

	Float3 Float3::Zero()
	{
		return Float3(0.0f);
	}
}