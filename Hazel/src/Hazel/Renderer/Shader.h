#pragma once

#include <string>

namespace Hazel {

	class Shader {

	public:
		Shader(const std::string& vertexSrc, const std::string& fragmanetSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}
