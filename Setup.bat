@echo off

echo. ********************
echo. *Setup Dependencies*
echo. ********************

if not exist .\External\vcpkg\bootstrap-vcpkg.bat (
	git submodule update --init --recursive
	call .\External\vcpkg\bootstrap-vcpkg.bat

	cd .\External\vcpkg\
	
	vcpkg install qt5 glslang glm qt5 opencv[*] --triplet x64-windows
	
	cd ..\..
)


cd ..
if not exist build_windows_vs17_win64 (
	
	mkdir build_windows_vs17_win64
	cd build_windows_vs17_win64

	cmake -G "Visual Studio 15 Win64" "../CoreTrack/" -DCMAKE_TOOLCHAIN_FILE=".\External\vcpkg\scripts\buildsystems\vcpkg.cmake"
)

rem TODO: Compile shaders





pause