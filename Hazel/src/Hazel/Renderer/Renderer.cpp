#include "hzpch.h"
#include "Renderer.h"

namespace Hazel {

	Camera Renderer::m_SceneCamera = Camera();
	void Renderer::BeginScene(Camera& camera)
	{
		m_SceneCamera = camera;
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexAray, std::shared_ptr<Shader>& shader)
	{
		shader->Bind();
		shader->SetMat4Uniform("uVPCamera", m_SceneCamera.GetViewMatrix());
		vertexAray->Bind();
		RenderCommand::DrawIndexed(vertexAray);
		shader->Unbind();
		vertexAray->UnBind();
	}

}