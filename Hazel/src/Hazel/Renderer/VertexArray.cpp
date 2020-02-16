#include "hzpch.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Plaform/OpenGL/OpenGLVertexArray.h"
#include "Hazel/Renderer/Renderer.h"

namespace Hazel {
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}
		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}