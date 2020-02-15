#include "Sandbox2D.h"
#include "imgui/imgui.h"
#include <glm/gtc/type_ptr.hpp>

#include <Plaform/OpenGL/OpenGLShader.h>

#include <chrono>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnUpdate(Hazel::Timestep ts) {

	HZ_PROFILE_FUNCTION("Sandbox2D::OnUpdate");
	{
		HZ_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}
	{
		HZ_PROFILE_SCOPE("Renderer Prep");

		Hazel::RenderCommand::SetClearColor({ 0.2f, 0.2f, 0.2f, 1 });
		Hazel::RenderCommand::Clear();
	}
	{
		HZ_PROFILE_SCOPE("Renderer Draw");

		Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());

		Hazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { m_SquareColor.r, m_SquareColor.b, 0.5f, 1.0f }, 45.0f);
		Hazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { m_SquareColor.r, m_SquareColor.b, 0.3f, 1.0f }, 30.0f);
		Hazel::Renderer2D::DrawQuad({ 0.2f,  0.5f, -0.1f }, { 6.5f, 6.75f }, m_CheckerboardTexture, 30.0f);

		Hazel::Renderer2D::EndScene();

	}
	//std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

}
void Sandbox2D::OnImGuiRender() {
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));


	ImGui::End();
}

void Sandbox2D::OnAttach() {
	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/checkerboard.png");

	
}

void Sandbox2D::OnDetach(){
	
}

void Sandbox2D::OnEvent(Hazel::Event& e) {
	m_CameraController.OnEvent(e);
}