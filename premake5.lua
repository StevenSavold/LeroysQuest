-- Premake5 file to generate project files for all supported platforms
-- Author: Steven Savold

-- workspace (Solution) for the entire emulator 
workspace "HW1_Leroys_Quest_Game"
    architecture "x86"
    configurations
    {
         "Debug",
         "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Leroys_Quest"
    location "Leroys_Quest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
	systemversion "latest"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.h"
    }

    includedirs
    {
        "%{prj.name}/src"
    }

    sysincludedirs
    {
        "%{prj.name}/src"
    }

    -- Filter for Debug configuration
    filter "configurations:Debug"
        defines 
        {
            "LEROY_DEBUG"
        }
        symbols "On" -- turn debug symbols ON

    -- Filter for Release configuration
    filter "configurations:Release"
        defines 
        {
            "LEROY_RELEASE"
        }
        optimize "Full" -- turn on Full optimizations