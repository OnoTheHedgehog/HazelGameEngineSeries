#pragma once
#include "Window.hpp"
#include "Event.hpp"
#include "Hazel/ApplicationEvent.hpp"

namespace Hazel{
  class Application {

  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& e);
  private:
    bool onWindowClose(WindowCloseEvent& e);
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
  };

  //To be defined in client
  Application* CreateApplication();

}
