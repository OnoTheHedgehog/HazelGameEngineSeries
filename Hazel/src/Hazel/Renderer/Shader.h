#pragma once

#include <string>
#include <glm/glm.hpp>

namespace Hazel {

	class Shader {

	public:
		Shader(const std::string& vertexSrc, const std::string& fragmanetSrc);
		~Shader();
		void SetMat4Uniform(const std::string& key, const glm::mat4& matix);
		void SetVec4Uniform(const std::string& key, const glm::vec4& vec);
		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}
