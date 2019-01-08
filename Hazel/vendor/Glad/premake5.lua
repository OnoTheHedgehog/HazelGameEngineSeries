project "Glad"

kind "StaticLib"
language "C"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
targetdir ("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
   "include/glad/glad.h",
   "include/KRH/khrplatform.h",
   "src/glad.c"
}

includedirs
{
   "include"
}
systemversion "latest"
staticruntime "On"

filter { "system:windows", "configurations:Release" }
buildoptions "/MT"
