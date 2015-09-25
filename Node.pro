QT += core xml
QT -= gui

TARGET = Node
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    node.cpp \
    controller.cpp

HEADERS += \
    node.h \
    controller.h

