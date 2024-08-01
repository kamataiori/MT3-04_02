#include "Result.h"

void Result::Initialize()
{
	position = { -0.90f,0.3f,0.0f, };
	angle = 0.0f;


	cameraRotate = { 0.0f,0.0f,0.0f };

	cameraTranslate = { 0.0f,0.0f,0.0f };
	cameraPosition = SphericalToCartesian(radius, theta, phi);
	cameraTarget = { 0.0f, 0.0f, 0.0f };
	cameraUp = { 0.0f, 1.0f, 0.0f };

	viewMatrix = MakeLookAtMatrix4x4(cameraPosition, cameraTarget, cameraUp);
	worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
	projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
	worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);
	viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
	viewMatrixProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

}

void Result::Update()
{
	if (start)
	{

	pendulum.angularAcceleration = -(9.8f / pendulum.length) * std::sin(pendulum.angle);
	pendulum.angularVelocity += pendulum.angularAcceleration * deltaTime;
	pendulum.angle += pendulum.angularVelocity * deltaTime;

	sphere.center.x = pendulum.anchor.x + std::sin(pendulum.angle) * pendulum.length;
	sphere.center.y = pendulum.anchor.y - std::cos(pendulum.angle) * pendulum.length;
	}

}

void Result::Draw()
{
	DrawSphere({ position,sphere.radius }, viewProjectionMatrix, viewportMatrix, sphere.color);
	screenBall = Transform(Transform(ball.position, viewMatrixProjectionMatrix), viewportMatrix);
	Vector3 	screenSpring = Transform(Transform(spring.anchor, viewMatrixProjectionMatrix), viewportMatrix);
	Novice::DrawLine((int)screenBall.x, (int)screenBall.y, (int)screenSpring.x, (int)screenSpring.y, WHITE);

	DrawGrid(viewProjectionMatrix, viewportMatrix);
	ImGui::Begin("Window");
	if (ImGui::Button("Start"))
	{
		start = true;
	}
	ImGui::End();
}
