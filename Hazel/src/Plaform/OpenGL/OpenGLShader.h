#pragma once
 
#include "Hazel/Renderer/Shader.h"
#include <glm/glm.hpp>

namespace Hazel {

	class OpenGLShader : public Shader {

	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmanetSrc);
		virtual ~OpenGLShader();
		void UploadUniformInt(const std::string& key, int value);

		void UploadUniformFloat(const std::string& key, float value);
		void UploadUniformFloat2(const std::string& key, const glm::vec2& vec);
		void UploadUniformFloat3(const std::string& key, const glm::vec3& vec);
		void UploadUniformFloat4(const std::string& key, const glm::vec4& vec);

		void UploadUniformMat3(const std::string& key, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& key, const glm::mat4& matrix);

		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		uint32_t m_RendererID;
	};
}