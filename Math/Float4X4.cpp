#include "Float4X4.h"
#include <iostream>

namespace qhy
{
	Float4X4::Float4X4(const Float4& _x, const Float4& _y, const Float4& _z, const Float4& _w)
	{
		r[0] = _x;
		r[1] = _y;
		r[2] = _z;
		r[3] = _w;
	}

	Float4X4::Float4X4(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
	: _11(m00), _12(m01), _13(m02), _14(m03),
		_21(m10), _22(m11), _23(m12), _24(m13),
		_31(m20), _32(m21), _33(m22), _34(m23),
		_41(m30), _42(m31), _43(m32), _44(m33) {}

	Float4X4::Float4X4(float e)
		: _11(e), _12(0), _13(0), _14(0),
		_21(0), _22(e), _23(0), _24(0),
		_31(0), _32(0), _33(e), _34(0),
		_41(0), _42(0), _43(0), _44(e) {}
	Float4& Float4X4::operator[](int n)
	{
		return r[n];
	}

	Float4X4& Float4X4::operator+=(Float4X4 const& q)
	{
		r[0] += q.r[0];
		r[1] += q.r[1];
		r[2] += q.r[2];
		r[3] += q.r[3];
		return *this;
	}
	Float4X4& Float4X4::operator-=(Float4X4 const& q)
	{
		r[0] -= q.r[0];
		r[1] -= q.r[1];
		r[2] -= q.r[2];
		r[3] -= q.r[3];
		return *this;
	}
	Float4X4& Float4X4::operator*=(Float4X4 const& q)
	{
		r[0] *= q.r[0];
		r[1] *= q.r[1];
		r[2] *= q.r[2];
		r[3] *= q.r[3];
		return *this;
	}
	Float4X4& Float4X4::operator*=(float q)
	{
		r[0] *= q;
		r[1] *= q;
		r[2] *= q;
		r[3] *= q;
		return *this;
	}


	Float4X4& Float4X4::operator/=(float q)
	{
		r[0] /= q;
		r[1] /= q;
		r[2] /= q;
		r[3] /= q;
		return *this;
	}


	Float4X4 Float4X4::operator+(Float4X4 const& q)
	{
		return Float4X4(r[0] + q.r[0], r[1] + q.r[1], r[2] + q.r[2], r[3] + q.r[3]);
	}

	Float4X4 Float4X4::operator-(Float4X4 const& q)
	{
		return Float4X4(r[0] - q.r[0], r[1] - q.r[1], r[2] - q.r[2], r[3] - q.r[3]);
	}
	Float4X4 Float4X4::operator*(Float4X4 const&q)
	{
		return Float4X4(r[0] * q, r[1] * q, r[2] * q, r[3] * q);
	}
	Float4 Float4X4::operator*(Float4 const& q)
	{
		return Float4(
			Float4::Sum(r[0] * q),
			Float4::Sum(r[1] * q),
			Float4::Sum(r[2] * q),
			Float4::Sum(r[3] * q));
	}
	Float4X4 Float4X4::operator*(float q)
	{
		return Float4X4(r[0] * q, r[1] * q, r[2] * q, r[3] * q);
	}
	Float4X4 Float4X4::operator/(float q)
	{
		return Float4X4(r[0] / q, r[1] / q, r[2] / q, r[3] / q);
	}

	void Float4X4::SelfTranspose()
	{
		std::swap(_12, _21);
		std::swap(_13, _31);
		std::swap(_14, _41);
		std::swap(_23, _32);
		std::swap(_24, _42);
		std::swap(_34, _43);
	}
	Float4X4 Float4X4::Transpose()
	{
		Float4X4 res = (*this);
		res.SelfTranspose();
		return res;
	}

	Float4X4 Float4X4::Identity()
	{
		return Float4X4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
	}
	void Float4X4::SetIdentity()
	{
		_11 = 1.0f; _12 = 0.0f; _13 = 0.0f; _14 = 0.0f;
		_21 = 0.0f; _22 = 1.0f; _23 = 0.0f; _24 = 0.0f;
		_31 = 0.0f; _32 = 0.0f; _33 = 1.0f; _34 = 0.0f;
		_41 = 0.0f; _42 = 0.0f; _43 = 0.0f; _44 = 1.0f;
	}

	Float4& operator *= (Float4& p, const Float4X4& q)
	{
		p = Float4(
			p.x * q._11 + p.y * q._21 + p.z * q._31 + p.w * q._41,
			p.x * q._12 + p.y * q._22 + p.z * q._32 + p.w * q._42,
			p.x * q._13 + p.y * q._23 + p.z * q._33 + p.w * q._43,
			p.x * q._14 + p.y * q._24 + p.z * q._34 + p.w * q._44);
		return p;
	}
	Float4 operator * (const Float4& p, const Float4X4& q)
	{
		return Float4(
			p.x * q._11 + p.y * q._21 + p.z * q._31 + p.w * q._41,
			p.x * q._12 + p.y * q._22 + p.z * q._32 + p.w * q._42,
			p.x * q._13 + p.y * q._23 + p.z * q._33 + p.w * q._43,
			p.x * q._14 + p.y * q._24 + p.z * q._34 + p.w * q._44);
	}
}