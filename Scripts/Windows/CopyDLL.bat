@echo off

if not exist ..\..\External\opencv\ (
	Echo "Dependency: OpenCV does not exists"
	Exit
)

if not exist ..\..\build-Clockwise-Desktop_Qt_5_11_2_MSVC2017_64bit-Debug (
	Echo "Target folder does not exists"
	Exit
)

xcopy ..\..\External\opencv\build\x64\vc15\bin\*.dll  ..\..\build-Clockwise-Desktop_Qt_5_11_2_MSVC2017_64bit-Debug\debug /y