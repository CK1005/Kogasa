#pragma once

#include <cmath>
#include "Float2.h"
#include "Float3.h"
#include "Float4.h"
#include "Float4X4.h"

namespace qhy
{
	float dot(Float2 a, Float2 b);
	float dot(Float3 a, Float3 b);
	float dot(Float4 a, Float4 b);

	Float3 cross(Float3 a, Float3 b);
}