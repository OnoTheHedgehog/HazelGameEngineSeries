#pragma once

#include "Hazel/Core/Core.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include <Hazel/Core/Window.h>
#include <Hazel/ImGui/ImGuiLayer.h>

#include "Hazel/Core/Timestep.h"

#include <Hazel/Core/LayerStack.h>



namespace Hazel {
	class Application
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
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime;
	private:
		static Application* s_Instance;

	};

	//To be defined in client
	Application* CreateApplication();
}

