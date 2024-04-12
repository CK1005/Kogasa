#include "LinearAlgebra.h"

namespace qhy
{
	float dot(Float2 a, Float2 b)
	{
		return a.x * b.x + a.y * b.y;
	}
	float dot(Float3 a, Float3 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	float dot(Float4 a, Float4 b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	Float3 cross(Float3 a, Float3 b)
	{
		return Float3(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	}
}