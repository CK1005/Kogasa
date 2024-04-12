#pragma once

#include <cmath>

namespace qhy
{
	struct Float3
	{
		union
		{
			float c[3];
			struct
			{
				union { float x, r; };
				union { float y, g; };
				union { float z, b; };
			};

		};


		Float3() = default;
		Float3(Float3 const& q) = default;
		Float3(float _x, float _y, float _z);
		Float3(float q);
		float& operator[](int i);

		Float3& operator=(Float3 const& q) = default;
		Float3& operator+=(Float3 const& q);
		Float3& operator-=(Float3 const& q);
		Float3& operator*=(Float3 const& q);
		//Float3& operator*=(Float3X4 const& q);
		Float3& operator*=(float q);
		Float3& operator/=(Float3 const& q);
		Float3& operator/=(float q);


		Float3 operator+(Float3 const& q);
		Float3 operator-(Float3 const& q);
		Float3 operator*(Float3 const& q);
		//Float3 operator*(Float3X4 const& q);
		Float3 operator*(float q);
		Float3 operator/(Float3 const& q);
		Float3 operator/(float q);

		float Sum();
		static float Sum(Float3& q);
		float Length();
		void Normalize();

		void Zeroing();
		static Float3 Zero();
	};
}