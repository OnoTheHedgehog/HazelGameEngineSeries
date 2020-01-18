#include "hzpch.h"
#include "Renderer.h"
#include "Plaform/OpenGL/OpenGLShader.h"

namespace Hazel {
	
	Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData;

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexAray, const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("uVPCamera", s_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);
		vertexAray->Bind();
		RenderCommand::DrawIndexed(vertexAray);
	}

}