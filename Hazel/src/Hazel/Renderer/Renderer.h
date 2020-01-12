#pragma once

#include "RenderCommand.h"
#include <Hazel\Renderer\OrthographicCamera.h>
#include <Hazel\Renderer\Shader.h>

namespace Hazel {



	class Renderer
	{
	private:
		struct SceneData {
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* s_SceneData;
	public:

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexAray);

		inline static  RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}