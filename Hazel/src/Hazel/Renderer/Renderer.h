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
		static void Init();

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(Ref<Shader>& shader, const Ref<VertexArray>& vertexAray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static  RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}