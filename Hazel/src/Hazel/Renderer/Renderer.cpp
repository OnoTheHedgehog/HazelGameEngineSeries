#include "hzpch.h"
#include "Renderer.h"

namespace Hazel {
	
	Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData;

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexAray)
	{
		shader->Bind();
		shader->SetMat4Uniform("uVPCamera", s_SceneData->ViewProjectionMatrix);
		vertexAray->Bind();
		RenderCommand::DrawIndexed(vertexAray);
	}

}