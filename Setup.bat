@echo off

echo. ********************
echo. *Setup Dependencies*
echo. ********************

set startDate=%date%
set startTime=%time%

if not exist .\External\vcpkg\bootstrap-vcpkg.bat (
	git submodule update --init --recursive
	call .\External\vcpkg\bootstrap-vcpkg.bat

	cd .\External\vcpkg\
	
	vcpkg install vulkan qt5 glslang glm opencv[*] ffmpeg[ffserver,ffplay,ffprobe,lzma,x264,opencl,nonfree,gpl] --triplet x64-windows
	
	cd ..\..
)


cd ..
if not exist build_windows_vs17_win64 (
	
	mkdir build_windows_vs17_win64
	cd build_windows_vs17_win64

	cmake -G "Visual Studio 15 Win64" "../CoreTrack/" -DCMAKE_TOOLCHAIN_FILE=".\External\vcpkg\scripts\buildsystems\vcpkg.cmake"
)


set endDate=%date%
set endTime=%time%

rem TODO: Compile shaders

echo. ======================================
echo. Time overview
echo.  
echo. Start date: %startDate% 
echo. Start time: %startTime%
echo.  
echo. End date:   %endDate%
echo. End time:   %endTime%
echo. ======================================

pause