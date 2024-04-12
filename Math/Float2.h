#pragma once

namespace qhy
{
	struct Float2
	{
		union
		{
			float c[2];
			struct
			{
				union { float x, r; };
				union { float y, g; };
			};

		};


		Float2() = default;
		Float2(Float2 const& q) = default;
		Float2(float _x, float _y);
		Float2(float q);
		float& operator[](int i);

		Float2& operator=(Float2 const& q) = default;
		Float2& operator+=(Float2 const& q);
		Float2& operator-=(Float2 const& q);
		Float2& operator*=(Float2 const& q);
		//Float2& operator*=(Float2X4 const& q);
		Float2& operator*=(float q);
		Float2& operator/=(Float2 const& q);
		Float2& operator/=(float q);


		Float2 operator+(Float2 const& q);
		Float2 operator-(Float2 const& q);
		Float2 operator*(Float2 const& q);
		//Float2 operator*(Float2X4 const& q);
		Float2 operator*(float q);
		Float2 operator/(Float2 const& q);
		Float2 operator/(float q);

		float Sum();
		static float Sum(Float2& q);

		void Zeroing();
		static Float2 Zero();
	};
}