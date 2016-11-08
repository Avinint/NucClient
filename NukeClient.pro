QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = NukeClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sockettest.cpp

HEADERS += \
    sockettest.h
