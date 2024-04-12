
#include "Float4.h"

namespace qhy
{
	Float4::Float4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Float4::Float4(float q)
	{
		x = y = z = w = q;
	}

	Float4::Float4(Float3 q, float qw)
	{
		x = q.x;
		y = q.y;
		z = q.z;
		w = qw;
	}

	float& Float4::operator[](int i)
	{
		return c[i];
	}

	Float4& Float4::operator+=(Float4 const& q)
	{
		x += q.x;
		y += q.y;
		z += q.z;
		w += q.w;
		return *this;
	}
	Float4& Float4::operator-=(Float4 const& q)
	{
		x -= q.x;
		y -= q.y;
		z -= q.z;
		w -= q.w;
		return *this;
	}
	Float4& Float4::operator*=(Float4 const& q)
	{
		x *= q.x;
		y *= q.y;
		z *= q.z;
		w *= q.w;
		return *this;
	}
	//Float4& Float4::operator*=(Float4X4 const& q);
	Float4& Float4::operator*=(float q)
	{
		x *= q;
		y *= q;
		z *= q;
		w *= q;
		return *this;

	}
	Float4& Float4::operator/=(Float4 const& q)
	{
		x /= q.x;
		y /= q.y;
		z /= q.z;
		w /= q.w;
		return *this;
	}
	Float4& Float4::operator/=(float q)
	{
		x /= q;
		y /= q;
		z /= q;
		w /= q;
		return *this;
	}


	Float4 Float4::operator+(Float4 const& q)
	{
		return Float4(x + q.x, y + q.y, z + q.z, w + q.w);
	}
	Float4 Float4::operator-(Float4 const& q)
	{
		return Float4(x - q.x, y - q.y, z - q.z, w - q.w);
	}
	Float4 Float4::operator*(Float4 const& q)
	{
		return Float4(x * q.x, y * q.y, z * q.z, w * q.w);
	}
	//Float4 Float4::operator*(Float4X4 const& q);
	Float4 Float4::operator*(float q)
	{
		return Float4(x * q, y * q, z * q, w * q);
	}
	Float4 Float4::operator/(Float4 const& q)
	{
		return Float4(x / q.x, y / q.y, z / q.z, w / q.w);
	}
	Float4 Float4::operator/(float q)
	{
		return Float4(x / q, y / q, z / q, w / q);
	}

	float Float4::Sum()
	{
		return x + y + z + w;
	}
	float Float4::Sum(Float4& q)
	{
		return q.Sum();
	}

	void Float4::Zeroing()
	{
		x = y = z = w = 0.0f;
	}

	Float4 Float4::Zero()
	{
		return Float4(0.0f);
	}
}