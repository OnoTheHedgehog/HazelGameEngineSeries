#pragma once
#include "Window.hpp"
#include "Hazel/layerStack.hpp"
#include "Event.hpp"
#include "Hazel/ApplicationEvent.hpp"

namespace Hazel{
  class Application {

  public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);
  private:
    bool onWindowClose(WindowCloseEvent& e);
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
    LayerStack m_LayerStack;
  };

  //To be defined in client
  Application* CreateApplication();

}
