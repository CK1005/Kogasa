#pragma once

#include "Float3.h"

namespace qhy
{
	struct Float4
	{
		union
		{
			float c[4];
			struct
			{
				union { float x, r; };
				union { float y, g; };
				union { float z, b; };
				union { float w, a; };
			};

		};


		Float4() = default;
		Float4(Float4 const& q) = default;
		Float4(float _x, float _y, float _z, float _w);
		Float4(float q);
		Float4(Float3 q, float qw);
		float& operator[](int i);

		Float4& operator=(Float4 const& q) = default;
		Float4& operator+=(Float4 const& q);
		Float4& operator-=(Float4 const& q);
		Float4& operator*=(Float4 const& q);
		//Float4& operator*=(Float4X4 const& q);
		Float4& operator*=(float q);
		Float4& operator/=(Float4 const& q);
		Float4& operator/=(float q);


		Float4 operator+(Float4 const& q);
		Float4 operator-(Float4 const& q);
		Float4 operator*(Float4 const& q);
		//Float4 operator*(Float4X4 const& q);
		Float4 operator*(float q);
		Float4 operator/(Float4 const& q);
		Float4 operator/(float q);

		float Sum();
		static float Sum(Float4& q);

		void Zeroing();
		static Float4 Zero();
	};
}