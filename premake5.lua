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


project "Sandbox"
location "Sandbox"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
   "%{prj.name}/src/**.cpp",
}

includedirs
{
   "%{prj.name}/src",
   "%{prj.name}/vendor/spdlog/include"
}

postbuildcommands
{
  ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/%{cfg.buildtarget.name}")
}

filter "system:windows"
cppdialect "C++17"
staticruntime "On"
systemversion "latest"

defines
{
   "HZ_PLATFORM_WINDOWS",
   "HZ_BUILD_DLL",
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






