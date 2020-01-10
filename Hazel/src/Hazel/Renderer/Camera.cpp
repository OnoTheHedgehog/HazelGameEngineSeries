#include "hzpch.h"
#include "Camera.h"

Hazel::Camera::Camera()
{
}

Hazel::Camera::Camera(glm::f32mat4 translation, glm::f32mat4 rotation)
	: m_MatRotation(rotation), m_MatTranslation(translation)
{
}

const glm::f32mat4& Hazel::Camera::GetRotation() const
{
	return m_MatRotation;
}

const glm::f32mat4& Hazel::Camera::GetTranslation() const
{
	return m_MatTranslation;
}

glm::f32mat4 Hazel::Camera::GetViewMatrix() const
{
	glm::f32mat4 res = m_MatTranslation * m_MatRotation;
	return glm::inverse(res);
}
