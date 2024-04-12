#pragma once

#include <cmath>
#include "LinearAlgebra.h"

namespace qhy
{
	static const float PI = 3.14159265358979323846f;
	//变换矩阵，以左向量乘以右矩阵
	//            |m00,m01,m02,m03|
	//(x,y,z,w) * |m10,m11,m12,m13| = (x',y',z',w')
	//            |m20,m21,m22,m23|
	//            |m30,m31,m32,m33|
	namespace trans
	{
		Float4X4 GetTranslationMatrix(Float3 translation);

		Float4X4 GetRotationMatrix(Float3 rotation);

		Float4X4 GetRotationXMatrix(float angle);
		Float4X4 GetRotationYMatrix(float angle);
		Float4X4 GetRotationZMatrix(float angle);

		Float4X4 GetScaleMatrix(Float3 scale);

		Float4X4 GetObjectToWorldMatrix(Float3 translation, Float3 rotation, Float3 scale);

		//视线方向(direction)为Float3(0,0,1,0)*GetRotationMatrix(rotation)
		// y(up)
		// |   
		// |  z(direction)
		// | /
		// |/
		// -----------x(tangent)
		Float4X4 GetViewMatrix(Float3 position, Float3 rotation);

		//look at
		Float4X4 GetViewMatrix(Float3 eye, Float3 at, Float3 up);
		
		Float4X4 GetOrthoMatrix(float left, float right, float bottom, float top, float zNear, float zFar);
		Float4X4 GetPerspectiveMatrix(float fovAngleY, float aspect, float zNear, float zFar);
		Float4X4 GetPerspectiveMatrix(float left, float right, float bottom, float top, float zNear, float zFar);
	}
}