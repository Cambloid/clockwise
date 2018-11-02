@echo off

rem Check if External Folder exist
rem Build Eigen
if not exist External (
	mkdir External
	
	rem Create eigen directories
	mkdir External\eigen
	mkdir External\eigen\eigen_build
	mkdir External\eigen\eigen_install
	
	rem Create gflags directories
	mkdir External\gflags
	mkdir External\gflags\gflags_build
	mkdir External\gflags\gflags_install
	
	rem Create glog directories
	mkdir External\glog
	mkdir External\glog\glog_build
	mkdir External\glog\glog_install
	
	rem Create ceres directories
	mkdir External\ceres
	mkdir External\ceres\ceres_build
	mkdir External\ceres\ceres_install
	
	rem Create opencv directories
	mkdir External\opencv
	mkdir External\opencv\opencv_build
	mkdir External\opencv\opencv_install
)

echo *********************************
echo *          Build eigen          *
echo *********************************
pushd External\eigen
git clone https://github.com/eigenteam/eigen-git-mirror.git
popd


pushd External\eigen\eigen_build
cmake -G "Visual Studio 15 2017" -DCMAKE_INSTALL_PREFIX=../eigen_install ..\eigen-git-mirror
cmake --build . --config Release --target install
popd


echo *********************************
echo *          Build gflags         *
echo *********************************
pushd External\gflags
git clone https://github.com/CoreTrackProject/gflags.git
popd

pushd External\gflags\gflags_build
cmake -G "Visual Studio 15 2017" -DCMAKE_INSTALL_PREFIX=../gflags_install ..\gflags
cmake --build . --config Release --target install
popd


echo *********************************
echo *          Build glog           *
echo *********************************
pushd External\glog
git clone https://github.com/CoreTrackProject/glog.git
popd

pushd External\glog\glog_build
cmake -G "Visual Studio 15 2017" -DCMAKE_INSTALL_PREFIX=../glog_install -Dgflags_DIR=../../gflags/gflags_build ..\glog
cmake --build . --config Release --target install
popd


rem cmake -G "Visual Studio 15 2017" -DEIGEN_INCLUDE_DIR="../../eigen/eigen_install/include/eigen3" -DCMAKE_INSTALL_PREFIX="../ceres_install" ..\ceres-solver
echo *********************************
echo *          Build ceres          *
echo *********************************
pushd External\ceres
git clone https://github.com/CoreTrackProject/ceres-solver.git
popd

pushd External\ceres\ceres_build
cmake -G "Visual Studio 15 2017" -DCMAKE_INSTALL_PREFIX="../ceres_install" -DMINIGLOG=1 -DEIGEN_INCLUDE_DIR="../../eigen/eigen_install/include/eigen3" -DEIGEN_INCLUDE_DIR_HINTS="../../eigen/eigen_install/include/eigen3" ..\ceres-solver
cmake --build . --config Release --target install
popd



pause

echo *********************************
echo *          Build opencv         *
echo *********************************
pushd External\opencv
git clone https://github.com/CoreTrackProject/opencv.git
git clone https://github.com/CoreTrackProject/opencv_contrib.git
popd

pushd External\opencv\opencv_build
cmake -G "Visual Studio 15 2017" -DEIGEN_INCLUDE_PATH=../../eigen/eigen_install/include -DOPENCV_ENABLE_NONFREE=1 -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules -DCMAKE_INSTALL_PREFIX=../opencv_install ..\opencv
cmake --build . --config Release --target install
popd

