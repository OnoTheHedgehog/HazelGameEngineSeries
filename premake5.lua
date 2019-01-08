workspace "Hazel"

architecture "x86_64"
require "export-compile-commands"

configurations
{
   "Debug",
   "Release",
   "Dist"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relaticve to the root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include" -- sets the include for pglfw in a struct
IncludeDir["Glad"] = "Hazel/vendor/Glad/include" -- sets the include for pglfw in a struct

include "Hazel/vendor/GLFW" -- includes premake file in GLFW
include "Hazel/vendor/Glad" -- includes premake file in GLFW

project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "hzpch.hpp"		

files
{
   "%{prj.name}/src/**.h",
   "%{prj.name}/src/**.cpp",
}

includedirs
{
   "Hazel/vendor/spdlog/include",
   "Hazel/src"
}

links
{
   "Hazel"
}

filter "system:windows"
staticruntime "On"
systemversion "latest"

defines
{
   "HZ_PLATFORM_WINDOWS"
}

filter "configurations:Debug"
defines { "HZ_DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "HZ_RELEASE" }
optimize "On"

filter "configurations:Dist"
defines { "HZ_DIST" }
optimize "On"




project "Hazel"
location "Hazel"
kind "SharedLib"
language "C++"
cppdialect "C++17"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
   "%{prj.name}/src/**.h",
   "%{prj.name}/src/**.cpp"
}

includedirs
{
   "%{prj.name}/src",
   "%{prj.name}/vendor/spdlog/include",
   "%{IncludeDir.GLFW}",
   "%{IncludeDir.Glad}"
}

links
{
   "GLFW",
   "Glad",
   "Cocoa.framework",
   "CoreVideo.framework",
   "OpenGL.framework",
   "IOKit.framework",
}

postbuildcommands
{
  ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/%{cfg.buildtarget.name}")
}

defines
{
   "GLFW_INCLUDE_NONE"
}


filter "configurations:Debug"
defines { "HZ_DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "HZ_RELEASE" }
optimize "On"

filter "configurations:Dist"
defines { "HZ_DIST" }
optimize "On"

filter "system:windows"
cppdialect "C++17"
staticruntime "On"
systemversion "latest"

defines
{
   "HZ_PLATFORM_WINDOWS",
   "HZ_BUILD_DLL",
}










