#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_core400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_core400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgcodecs400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgcodecs400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgproc400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgproc400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_highgui400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_highgui400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_img_hash400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_img_hash400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_xfeatures2d400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_xfeatures2d400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_features2d400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_features2d400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_flann400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_flann400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_tracking400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_tracking400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_video400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_video400d

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_videoio400
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_videoio400d


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_core343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_core343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_imgcodecs343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_imgcodecs343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_imgproc343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_imgproc343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_video343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_video343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_videoio343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_videoio343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_videostab343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_videostab343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_highgui343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_highgui343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_img_hash400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_img_hash343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_xfeatures2d343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_xfeatures2d343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_features2d343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_features2d343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_flann343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_flann343d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/lib/ -lopencv_tracking343
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/vcpkg/installed/x64-windows/debug/lib/ -lopencv_tracking343d



INCLUDEPATH += $$PWD/../External/vcpkg/installed/x64-windows/include
DEPENDPATH += $$PWD/../External/vcpkg/installed/x64-windows/include
