#include "hzpch.h"
#include "VertexArray.h"
#include "Plaform/OpenGL/OpenGLShader.h"
#include "Renderer.h"

namespace Hazel {
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmanetSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmanetSrc);
		}
		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}