#include "hzpch.h"
#include "Renderer.h"

namespace Hazel {


	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexAray)
	{
		vertexAray->Bind();
		RenderCommand::DrawIndexed(vertexAray);
	}

}