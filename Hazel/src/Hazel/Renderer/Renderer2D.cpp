#include "hzpch.h"

#include "Renderer2D.h"

#include "VertexArray.h"
#include "Shader.h"

#include "Plaform/OpenGL/OpenGLShader.h"
#include <glm/gtc/matrix_transform.hpp>

#include "RenderCommand.h"

namespace Hazel {

	struct Renderer2DStorage
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> FlatColorShader;
	};

	static Renderer2DStorage* s_Data;

	void Renderer2D::Init() {


		s_Data =  new Renderer2DStorage();

		s_Data->QuadVertexArray = VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		Ref<VertexBuffer> squareVB;
		squareVB = VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		BufferLayout squareLayout = {
			{ ShaderDataType::Float3, "a_Position" }
		};
		squareVB->SetLayout(squareLayout);
		s_Data->QuadVertexArray->AddVertexBuffer(squareVB);
		uint32_t squareIndices[6]{ 0, 1, 2, 2, 3, 0 };
		Ref<IndexBuffer> squareIB;
		squareIB = IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		s_Data->QuadVertexArray->SetIndexBuffer(squareIB);

		s_Data->FlatColorShader = Shader::Create("assets/shaders/FlatColor.glsl");
	}
	void Renderer2D::Shutdown(){
		delete s_Data;
	}


	void Renderer2D::BeginScene(const OrthographicCamera& camera){
		s_Data->FlatColorShader->Bind();
		s_Data->FlatColorShader->SetMat4("uVPCamera", camera.GetViewProjectionMatrix());
	}
	void Renderer2D::EndScene(){

	}

	// Primitives
	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color, float angle = 0.0f){
		DrawQuad({position.x, position.y, 0.0f}, size, color, angle);
	}
	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color, float angle = 0.0f){
		s_Data->FlatColorShader->Bind();
		s_Data->FlatColorShader->SetFloat4("u_Color", color);

		glm::mat4 transform = glm::translate(glm::mat4(1.0), position) * glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3{ 0, 0, 1 }) *
			glm::scale(glm::mat4(1.0), { size.x, size.y, 1.0f });

		s_Data->FlatColorShader->SetMat4("u_Transform", transform);

		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

}