#-------------------------------------------------
#
# Project created by QtCreator 2018-09-24T14:44:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoreTrack
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        UI/MainWindow/MainWindow.cpp \
        UI/SettingsWindow/SettingsWindow.cpp \
        FeatureDetection/CornerHarrisDetector.cpp \
        FeatureDetection/ShiTomasiDetector.cpp \
        FeatureDetection/ORBDetector.cpp \
        FeatureDetection/SIFTDetector.cpp \
        FeatureDetection/DetectorManager.cpp \
        FeatureMatching/FLANNMatcher.cpp \
        Image/ImageContainer.cpp \
        Main.cpp

HEADERS += \
        UI/MainWindow/MainWindow.h \
        UI/SettingsWindow/SettingsWindow.h \
        DTO/SettingsBase.h \
        DTO/FeatureContainer.h \
        FeatureDetection/CornerHarrisDetector.h \
        FeatureDetection/ShiTomasiDetector.h \
        FeatureDetection/ORBDetector.h \
        FeatureDetection/SIFTDetector.h \
        FeatureDetection/DetectorManager.h \
        FeatureMatching/FLANNMatcher.h \
        Image/ImageConverter.hpp \
        Image/ImageUtils.hpp \
        Image/ImageLoader.hpp \
        Image/ImageContainer.h

FORMS += \
        UI/MainWindow/MainWindow.ui \
        UI/SettingsWindow/SettingsWindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_core400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_core400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_imgcodecs400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_imgcodecs400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_imgproc400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_imgproc400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_highgui400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_highgui400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_img_hash400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_img_hash400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_xfeatures2d400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_xfeatures2d400d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_features2d400
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../External/opencv/build/install/x64/vc15/lib/ -lopencv_features2d400d

INCLUDEPATH += $$PWD/../External/opencv/build/install/include
DEPENDPATH += $$PWD/../External/opencv/build/install/include

