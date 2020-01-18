#pragma once

#include "Hazel/Renderer/Shader.h"

namespace Hazel {

	class OpenGLShader : public Shader {

	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmanetSrc);
		virtual ~OpenGLShader() = default;
		void SetMat4Uniform(const std::string& key, const glm::mat4& matix);
		void SetVec4Uniform(const std::string& key, const glm::vec4& vec);
		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		uint32_t m_RendererID;
	};
}
