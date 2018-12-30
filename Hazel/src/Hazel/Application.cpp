#include "hzpch.hpp"
#include "Application.hpp"
#include "Hazel/Log.hpp"

#include "GLFW/glfw3.h"

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
  Application::Application(){
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    
  }
  Application::~Application(){
  }

  void Application::Run(){
    WindowResizeEvent e(1260, 720);
    HZ_TRACE(e);
    while (m_Running){
      glClearColor(1, 0, 1, 1);
      glClear(GL_COLOR_BUFFER_BIT);
      m_Window->OnUpdate();
    }
  }

  void Application::OnEvent(Event& e){
    HZ_CORE_TRACE("{0}", e);
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
  }

  bool Application::onWindowClose(WindowCloseEvent& e){
    m_Running = false;
    return true; 
  }
}
