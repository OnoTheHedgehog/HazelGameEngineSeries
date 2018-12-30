#include "hzpch.hpp"
#include "Log.hpp"
namespace Hazel {

  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
  
  void Log::Init(){
    spdlog::set_pattern("%^[%T] %n: %v%$");//pattern is timestamp then name of logger and then color
    s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
    s_ClientLogger = spdlog::stdout_color_mt("APP");
    s_ClientLogger->set_level(spdlog::level::trace);
    s_CoreLogger->set_level(spdlog::level::trace);
  }
    

}  // Hazel
