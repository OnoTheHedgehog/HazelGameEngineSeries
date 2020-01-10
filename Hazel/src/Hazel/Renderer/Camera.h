#pragma once

#include <glm/glm.hpp>


namespace Hazel {

	class Camera {
	private:
		glm::f32mat4 m_MatRotation;
		glm::f32mat4 m_MatTranslation;
	public:
		Camera();
		Camera(glm::f32mat4 translation, glm::f32mat4 rotation);
		const glm::f32mat4& GetRotation() const;
		const glm::f32mat4& GetTranslation() const;
		glm::f32mat4 GetViewMatrix() const;

	};
}