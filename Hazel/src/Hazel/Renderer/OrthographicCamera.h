#pragma once

#include <glm/glm.hpp>


namespace Hazel {

	class OrthographicCamera {
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = glm::vec3{ 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;

	private:
		void RecalculateViewMatrix();
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		const glm::vec3& GetPosition() { return m_Position; }
		float GetRotation() { return m_Rotation; }
		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); };
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); };
		void SetProjection(float left, float right, float bottom, float top);

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
	};
}