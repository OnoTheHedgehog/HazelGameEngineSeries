#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include <Hazel/Window.h>
#include <Hazel/ImGui/ImGuiLayer.h>
#include <Hazel/Renderer/Shader.h>
#include <Hazel/Renderer/Buffer.h>
#include <Hazel/Renderer/VertexArray.h>
#include <Hazel/LayerStack.h>


namespace Hazel {
	class Camera;
	class HAZEL_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		inline static Application& Get() {
			return *s_Instance;
		}
		inline Window& getWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		std::shared_ptr<Camera> m_Camera;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<VertexArray> m_SquareVertexArray;
		std::shared_ptr<Shader> blueShader;
		float m_x;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();
}

