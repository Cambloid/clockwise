win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_core400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_core400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgcodecs400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgcodecs400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgproc400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_imgproc400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_highgui400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_highgui400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_img_hash400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_img_hash400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_xfeatures2d400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_xfeatures2d400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_features2d400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_features2d400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_flann400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_flann400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_tracking400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_tracking400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_video400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/x64/vc15/lib/ -lopencv_video400d

INCLUDEPATH += $$PWD/../External/opencv/include
DEPENDPATH += $$PWD/../External/opencv/include
