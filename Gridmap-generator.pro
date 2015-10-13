TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH += /home/victor/workspace/ugv
INCLUDEPATH += /usr/include/opencv \
             /usr/include/opencv2
LIBS += `pkg-config opencv --cflags --libs` \
        -lglog\
       -lboost_system\
       -lboost_thread\
       -lboost_program_options\
       -lHdlEngine

DEFINES += OFFLINE
