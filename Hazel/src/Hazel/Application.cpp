#include "Application.hpp"
#include "ApplicationEvent.hpp"
#include "Log.hpp"

namespace Hazel {
  Application::Application(){
  
  }
  Application::~Application(){
  
  }

  void Application::Run(){
    WindowResizeEvent e(1260, 720);
    HZ_TRACE(e);
    while (true);
  }
  
}
