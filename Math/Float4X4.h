#pragma once

#include "Float4.h"

namespace qhy
{
	struct Float4X4
	{
		union
		{
			Float4 r[4];
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};

		Float4X4() = default;
		Float4X4(Float4X4 const& q) = default;
		Float4X4(const Float4& _x, const Float4& _y, const Float4& _z, const Float4& _w);
		Float4X4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);
		Float4X4(float e);
		
		Float4& operator[](int n);

		Float4X4& operator=(Float4X4 const& q) = default;
		Float4X4& operator+=(Float4X4 const& q);
		Float4X4& operator-=(Float4X4 const& q);
		Float4X4& operator*=(Float4X4 const& q);
		Float4X4& operator*=(float q);
		Float4X4& operator/=(float q);


		Float4X4 operator+(Float4X4 const& q);
		Float4X4 operator-(Float4X4 const& q);
		Float4X4 operator*(Float4X4 const& q);
		Float4 operator*(Float4 const& q);
		Float4X4 operator*(float q);
		Float4X4 operator/(float q);

		void SelfTranspose();
		Float4X4 Transpose();

		static Float4X4 Identity();
		void SetIdentity();
	};

	Float4& operator *= (Float4& p, const Float4X4& q);
	Float4 operator *(const Float4& p, const Float4X4& q);
}