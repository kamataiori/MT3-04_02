#include "MathFunc.h"

void MathFunc::DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix)
{
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubDivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubDivision);
	Vector3 start[kSubDivision + 1]{};
	Vector3 end[kSubDivision + 1]{};
	Vector3 ndcVertexStart[kSubDivision + 1]{};
	Vector3 screenVerticesStart[kSubDivision + 1]{};
	Vector3 ndcVertexEnd[kSubDivision + 1]{};
	Vector3 screenVerticesEnd[kSubDivision + 1]{};
	int color = 0xAAAAAAFF;

	for (uint32_t xIndex = 0; xIndex <= kSubDivision; xIndex++) {
		// Vector3 pos;

		start[xIndex].x = (-5.0f + xIndex) * kGridEvery; // start of the x line
		end[xIndex].x = (-5.0f + xIndex) * kGridEvery;
		start[xIndex].z = -kGridHalfWidth; // space between lines
		end[xIndex].z = kGridHalfWidth;
		// pos.x = -kGridHalfWidth + xIndex * kGridEvery; // Calculate the x position

		ndcVertexStart[xIndex] = Transform(start[xIndex], viewProjectionMatrix); // change into screen coord
		screenVerticesStart[xIndex] = Transform(ndcVertexStart[xIndex], viewportMatrix);
		ndcVertexEnd[xIndex] = Transform(end[xIndex], viewProjectionMatrix);
		screenVerticesEnd[xIndex] = Transform(ndcVertexEnd[xIndex], viewportMatrix);

		if (xIndex == 5) {
			color = BLACK;
		}
		else {
			color = 0xAAAAAAFF;
		}

		//Novice::ScreenPrintf(0, 30 * xIndex, "%f", start[xIndex].x);
		//Novice::ScreenPrintf(100, 30 * xIndex, "%f", end[xIndex].x);
		Novice::DrawLine((int)screenVerticesStart[xIndex].x, (int)screenVerticesStart[xIndex].y, (int)screenVerticesEnd[xIndex].x, (int)screenVerticesEnd[xIndex].y, color);
	}

	for (uint32_t zIndex = 0; zIndex <= kSubDivision; zIndex++) {

		start[zIndex].x = -kGridHalfWidth;
		end[zIndex].x = kGridHalfWidth;
		start[zIndex].z = (-5.0f + zIndex) * kGridEvery;
		end[zIndex].z = (-5.0f + zIndex) * kGridEvery;
		ndcVertexStart[zIndex] = Transform(start[zIndex], viewProjectionMatrix);
		screenVerticesStart[zIndex] = Transform(ndcVertexStart[zIndex], viewportMatrix);
		ndcVertexEnd[zIndex] = Transform(end[zIndex], viewProjectionMatrix);
		screenVerticesEnd[zIndex] = Transform(ndcVertexEnd[zIndex], viewportMatrix);
		// pos.x = -kGridHalfWidth + xIndex * kGridEvery; // Calculate the x position

		if (zIndex == 5) {
			color = BLACK;
		}
		else {
			color = 0xAAAAAAFF;
		}

		//Novice::ScreenPrintf(300, 30 * zIndex, "%f", start[zIndex].z);
		//Novice::ScreenPrintf(500, 30 * zIndex, "%f", end[zIndex].z);
		Novice::DrawLine((int)screenVerticesStart[zIndex].x, (int)screenVerticesStart[zIndex].y, (int)screenVerticesEnd[zIndex].x, (int)screenVerticesEnd[zIndex].y, color);
	}
}

void MathFunc::DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	const uint32_t kSubdivision = 20; // amount of lines
	const float pi = float(M_PI);
	const float longD = pi / kSubdivision;		// longitude of 1 line
	const float latiD = (2 * pi) / kSubdivision;	// latitude of 1 line

	for (uint32_t latIndex = 0; latIndex < kSubdivision; latIndex++) {
		float lat = (-pi / 2.0f) + (latiD * latIndex); // the latitude line we are currently on

		for (uint32_t longIndex = 0; longIndex < kSubdivision; longIndex++) {
			float lon = longIndex * longD; // the longitude line we are currently on

			Vector3 a, b, c;

			a = { cosf(lat) * cosf(lon) * sphere.radius + sphere.center.x, sinf(lat) * sphere.radius + sphere.center.y, cosf(lat) * sinf(lon) * sphere.radius + sphere.center.z };
			b = { cosf(lat + latiD) * cosf(lon) * sphere.radius + sphere.center.x, sinf(lat + latiD) * sphere.radius + sphere.center.y, cosf(lat + latiD) * sin(lon) * sphere.radius + sphere.center.z };
			c = { cosf(lat) * cosf(lon + longD) * sphere.radius + sphere.center.x, sinf(lat) * sphere.radius + sphere.center.y, cosf(lat) * sinf(lon + longD) * sphere.radius + sphere.center.z };

			Vector3 screenTransformA = Transform(Transform(a, viewProjectionMatrix), viewportMatrix);
			Vector3 screenTransformB = Transform(Transform(b, viewProjectionMatrix), viewportMatrix);
			Vector3 screenTransformC = Transform(Transform(c, viewProjectionMatrix), viewportMatrix);
			Novice::DrawLine((int)screenTransformA.x, (int)screenTransformA.y, (int)screenTransformB.x, (int)screenTransformB.y, color);
			Novice::DrawLine((int)screenTransformA.x, (int)screenTransformA.y, (int)screenTransformC.x, (int)screenTransformC.y, color);
		}
	}
}

Matrix4x4 MathFunc::Add(Matrix4x4& m1, Matrix4x4& m2)
{
	return Matrix4x4();
}

Vector3 MathFunc::Add(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

Matrix4x4 MathFunc::Subtract(Matrix4x4& m1, Matrix4x4& m2)
{
	return Matrix4x4();
}

Vector3 MathFunc::Subtract(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

Matrix4x4 MathFunc::Multiply(const Matrix4x4& m1, const Matrix4x4& m2)
{
	return Matrix4x4();
}

Vector3 MathFunc::Multiply(Vector3& v1, Vector3& v2)
{
	return Vector3();
}

Vector3 MathFunc::Multiply(const float& f, const Vector3& v1)
{
	return Vector3();
}

Matrix4x4 MathFunc::Inverse(Matrix4x4& m1)
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::Transpose(Matrix4x4& m1)
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::MakeIdentify4x4()
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::MakeScaleMatrix(Vector3& scale)
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::MakeTranslateMatrix(Vector3& transform)
{
	return Matrix4x4();
}

Vector3 MathFunc::Transform(const Vector3& vector, const Matrix4x4& Matrix)
{
	return Vector3();
}

void MathFunc::MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
}

void MathFunc::VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label)
{
}

Matrix4x4 MathFunc::MakeRotateXMatrix(float radian)
{
	Matrix4x4 result{ 1, 0, 0, 0, 0, std::cos(radian), std::sin(radian), 0, 0, -std::sin(radian), std::cos(radian), 0, 0, 0, 0, 1 };
	return result;
}

Matrix4x4 MathFunc::MakeRotateYMatrix(float radian)
{
	Matrix4x4 result{ std::cos(radian), 0, -std::sin(radian), 0, 0, 1, 0, 0, std::sin(radian), 0, std::cos(radian), 0, 0, 0, 0, 1 };
	return result;
}

Matrix4x4 MathFunc::MakeRotateZMatrix(float radian)
{
	Matrix4x4 result{ std::cos(radian), std::sin(radian), 0, 0, -std::sin(radian), std::cos(radian), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
	return result;
}

Matrix4x4 MathFunc::MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate)
{
	Matrix4x4 MakeRotateMatrixZ{ std::cos(rot.z), std::sin(rot.z), 0, 0, -std::sin(rot.z), std::cos(rot.z), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

	Matrix4x4 MakeRotateMatrixX{ 1, 0, 0, 0, 0, std::cos(rot.x), std::sin(rot.x), 0, 0, -std::sin(rot.x), std::cos(rot.x), 0, 0, 0, 0, 1 };

	Matrix4x4 MakeRotateMatrixY{ std::cos(rot.y), 0, -std::sin(rot.y), 0, 0, 1, 0, 0, std::sin(rot.y), 0, std::cos(rot.y), 0, 0, 0, 0, 1 };

	Matrix4x4 RotateYZ = Multiply(MakeRotateMatrixY, MakeRotateMatrixZ);

	Matrix4x4 Rotate = Multiply(MakeRotateMatrixX, RotateYZ);

	Matrix4x4 result{
		scale.x * Rotate.m[0][0],
		scale.x * Rotate.m[0][1],
		scale.x * Rotate.m[0][2],
		0,
		scale.y * Rotate.m[1][0],
		scale.y * Rotate.m[1][1],
		scale.y * Rotate.m[1][2],
		0,
		scale.z * Rotate.m[2][0],
		scale.z * Rotate.m[2][1],
		scale.z * Rotate.m[2][2],
		0,
		translate.x,
		translate.y,
		translate.z,
		1

	};

	return result;
}

Matrix4x4 MathFunc::MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip)
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip)
{
	return Matrix4x4();
}

Matrix4x4 MathFunc::MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth)
{
	return Matrix4x4();
}

Vector3 MathFunc::Cross(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

Vector3 MathFunc::Project(const Vector3& v1, const Vector3& v2)
{
	return Vector3();
}

Vector3 MathFunc::ClosestPoint(const Vector3& point, const Segment& segment)
{
	return Vector3();
}

float MathFunc::Length(const Vector3& point1, const Vector3& point2)
{
	return 0.0f;
}

Vector3 MathFunc::Perpendicular(const Vector3& vector)
{
	return Vector3();
}

void MathFunc::DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color, uint32_t color2, uint32_t color3, uint32_t color4)
{
}

void MathFunc::DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color)
{
}

void MathFunc::DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color)
{
}

Vector3 MathFunc::Normalize(Vector3 v)
{
	return Vector3();
}

float MathFunc::Dot(Vector3 v1, Vector3 v2)
{
	return 0.0f;
}

Vector3 MathFunc::Lerp(const Vector3& v1, const Vector3& v2, float t)
{
	return Vector3();
}

Vector3 MathFunc::Bezier(const Vector3& p0, const Vector3& p1, const Vector3& p2, float t)
{
	return Vector3();
}

void MathFunc::DrawBezier(const Vector3& controlPoint0, const Vector3& controlPoint1, const Vector3& controlPoint2, Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color)
{
}

Vector3 MathFunc::CatmullRom(const Vector3& p0, const Vector3& p1, const Vector3& p2, const Vector3& p3, float t)
{
	return Vector3();
}

void MathFunc::DrawCatmullRom(const Vector3& controlPoint0, const Vector3& controlPoint1, const Vector3& controlPoint2, const Vector3& controlPoint3, Matrix4x4& viewProjectionMatrix, const Matrix4x4 viewPortMatrix, uint32_t color)
{
}

void MathFunc::MakeSpring(Spring& spring, Ball& ball)
{
}

Vector3 MathFunc::divide(const Vector3& v1, float v2)
{
	return Vector3();
}


