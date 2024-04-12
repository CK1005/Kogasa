
#include "Float2.h"

namespace qhy
{
	Float2::Float2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	Float2::Float2(float q)
	{
		x = y = q;
	}

	float& Float2::operator[](int i)
	{
		return c[i];
	}

	Float2& Float2::operator+=(Float2 const& q)
	{
		x += q.x;
		y += q.y;
		return *this;
	}
	Float2& Float2::operator-=(Float2 const& q)
	{
		x -= q.x;
		y -= q.y;
		return *this;
	}
	Float2& Float2::operator*=(Float2 const& q)
	{
		x *= q.x;
		y *= q.y;
		return *this;
	}
	//Float2& Float2::operator*=(Float2X4 const& q);
	Float2& Float2::operator*=(float q)
	{
		x *= q;
		y *= q;
		return *this;

	}
	Float2& Float2::operator/=(Float2 const& q)
	{
		x /= q.x;
		y /= q.y;
		return *this;
	}
	Float2& Float2::operator/=(float q)
	{
		x /= q;
		y /= q;
		return *this;
	}


	Float2 Float2::operator+(Float2 const& q)
	{
		return Float2(x + q.x, y + q.y);
	}
	Float2 Float2::operator-(Float2 const& q)
	{
		return Float2(x - q.x, y - q.y);
	}
	Float2 Float2::operator*(Float2 const& q)
	{
		return Float2(x * q.x, y * q.y);
	}
	//Float2 Float2::operator*(Float2X4 const& q);
	Float2 Float2::operator*(float q)
	{
		return Float2(x * q, y * q);
	}
	Float2 Float2::operator/(Float2 const& q)
	{
		return Float2(x / q.x, y / q.y);
	}
	Float2 Float2::operator/(float q)
	{
		return Float2(x / q, y / q);
	}

	float Float2::Sum()
	{
		return x + y;
	}
	float Float2::Sum(Float2& q)
	{
		return q.Sum();
	}

	void Float2::Zeroing()
	{
		x = y = 0.0f;
	}

	Float2 Float2::Zero()
	{
		return Float2(0.0f);
	}
}