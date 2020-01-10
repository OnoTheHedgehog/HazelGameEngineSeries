#pragma once

#include "RenderCommand.h"
#include <Hazel\Renderer\Camera.h>
#include <Hazel\Renderer\Shader.h>

namespace Hazel {



	class Renderer
	{
	private:
		static Camera m_SceneCamera;
	public:

		static void BeginScene(Camera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexAray, std::shared_ptr<Shader>& shader);

		inline static  RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}