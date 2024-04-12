#include "Transformation.h"

namespace qhy
{
	//变换矩阵，
	namespace trans
	{
		
		Float4X4 GetTranslationMatrix(Float3 translation)
		{
			Float4X4 res = Float4X4::Identity();
			res[3] = Float4(translation, 1.0f);
			return res;
		}

		Float4X4 GetRotationMatrix(Float3 rotation)
		{
			return GetRotationXMatrix(rotation[0])
				* GetRotationYMatrix(rotation[1])
				* GetRotationZMatrix(rotation[2]);
		}

		Float4X4 GetRotationXMatrix(float angle)
		{
			Float4X4 res = Float4X4::Identity();
			float c = cos(angle);
			float s = sin(angle);
			res[1][1] = c;
			res[1][2] = s;
			res[2][1] = -s;
			res[2][2] = c;
			return res;
		}

		Float4X4 GetRotationYMatrix(float angle)
		{
			Float4X4 res = Float4X4::Identity();
			float c = cos(angle);
			float s = sin(angle);
			res[0][0] = c;
			res[0][2] = -s;
			res[2][0] = s;
			res[2][2] = c;
			return res;
		}

		Float4X4 GetRotationZMatrix(float angle)
		{
			Float4X4 res = Float4X4::Identity();
			float c = cos(angle);
			float s = sin(angle);
			res[0][0] = c;
			res[0][1] = s;
			res[1][0] = -s;
			res[1][1] = c;
			return res;
		}

		Float4X4 GetScaleMatrix(Float3 scale)
		{
			Float4X4 res(1.0f);
			res[0][0] = scale[0];
			res[1][1] = scale[1];
			res[2][2] = scale[2];
			return res;
		}

		Float4X4 GetObjectToWorldMatrix(Float3 translation, Float3 rotation, Float3 scale)
		{
			return GetScaleMatrix(scale)
				* GetRotationMatrix(rotation)
				* GetTranslationMatrix(translation);
		}

		//视线方向为Float3(0,0,1)*GetRotationMatrix(rotation)
		Float4X4 GetViewMatrix(Float3 position, Float3 rotation)
		{
			Float4X4 res = GetRotationMatrix(rotation);
			res[0][3] = -dot(position, Float3(res[0].x, res[0].y, res[0].z));
			res[1][3] = -dot(position, Float3(res[1].x, res[1].y, res[1].z));
			res[2][3] = -dot(position, Float3(res[2].x, res[2].y, res[2].z));
			res.SelfTranspose();
			return res;
		}

		//look at
		Float4X4 GetViewMatrix(Float3 eye, Float3 at, Float3 up)
		{
			Float3 dir = at - eye;
			dir.Normalize();
			up.Normalize();
			Float3 tangent = cross(up, dir);
			Float4X4 res = Float4X4::Identity();
			res[0] = Float4(tangent, 0.0f);
			res[1] = Float4(up, 0.0f);
			res[2] = Float4(dir, 0.0f);
			res[0][3] = -dot(eye, Float3(res[0].x, res[0].y, res[0].z));
			res[1][3] = -dot(eye, Float3(res[1].x, res[1].y, res[1].z));
			res[2][3] = -dot(eye, Float3(res[2].x, res[2].y, res[2].z));
			res.SelfTranspose();
			return res;
		}

		Float4X4 GetOrthoMatrix(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			Float4X4 res = Float4X4(0.0f);
			res[0][0] = 2.0f / (right - left);
			res[1][1] = 2.0f / (top - bottom);
			res[2][2] = 1.0f / (zFar - zNear);
			res[3][0] = -(right + left) / (right - left);
			res[3][1] = -(top + bottom) / (top - bottom);
			res[3][2] = -zNear / (zFar - zNear);
			res[3][3] = 1.0f;

			return res;
		}

		//fovAngleY采用弧度制
		Float4X4 GetPerspectiveMatrix(float fovAngleY, float aspect, float zNear, float zFar)
		{
			Float4X4 res = Float4X4(0.0f);
			float tanF = tan(fovAngleY / 2);
			res[0][0] = 1.0f / tanF * aspect;
			res[1][1] = 1.0f / tanF;
			res[2][2] = zFar / (zFar - zNear);
			res[2][3] = 1.0;
			res[3][2] = -(zFar * zNear) / (zFar - zNear);
			 
			return res;
		}

		Float4X4 GetPerspectiveMatrix(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			Float4X4 res = Float4X4(0.0f);
			res[0][0] = 2.0 * zNear / (right - left);
			res[1][1] = 2.0 * zNear / (top - bottom);
			res[2][0] = -(right + left) / (right - left);
			res[2][1] = -(top + bottom) / (top - bottom);
			res[2][2] = zFar / (zFar - zNear);
			res[2][3] = 1.0;
			res[3][2] = - zFar * zNear / (zFar - zNear);

			return res;
		}
	}
}