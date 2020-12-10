#pragma once

#include <include/glm.h>

namespace Transform3D
{
	// Translate matrix
	inline glm::mat4 MyTranslate(float translateX, float translateY, float translateZ)
	{
		return glm::mat4(
			1.f, 0.f, 0.f, 0.f,
			0.f, 1.f, 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			translateX, translateY, translateZ, 1.f
		);
	}

	// Scale matrix
	inline glm::mat4 MyScale(float scaleX, float scaleY, float scaleZ)
	{
		return glm::mat4(
			scaleX, 0.f, 0.f, 0.f,
			0.f, scaleY, 0.f, 0.f,
			0.f, 0.f, scaleZ, 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}

	// Rotate matrix relative to the OZ axis
	inline glm::mat4 RotateOZ(float radians)
	{
		float c = cos(radians);
		float s = sin(radians);

		return glm::mat4(
			cos(radians), sin(radians), 0.f, 0.f,
			-sin(radians), cos(radians), 0.f, 0.f,
			0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}

	// Rotate matrix relative to the OY axis
	inline glm::mat4 RotateOY(float radians)
	{

		return glm::mat4(
			cos(radians), 0.f, -sin(radians), 0.f,
			0.f, 1.f, 0.f, 0.f,
			sin(radians), 0.f, cos(radians), 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}

	// Rotate matrix relative to the OX axis
	inline glm::mat4 RotateOX(float radians)
	{

		return glm::mat4(
			1.f, 0.f, 0.f, 0.f,
			0.f, cos(radians), sin(radians), 0.f,
			0.f, -sin(radians), cos(radians), 0.f,
			0.f, 0.f, 0.f, 1.f
		);
	}
}