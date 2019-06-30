#-------------------------------------------------
#
# Project created by QtCreator 2019-06-20T22:14:51
#
#-------------------------------------------------


QT += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = QBar
TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += Modello/Gerarchia/prodotto.cpp \
    Modello/Gerarchia/cibo.cpp \
    Modello/Gerarchia/bevanda.cpp \
    Modello/Gerarchia/brioche.cpp \
    Modello/Gerarchia/panino.cpp \
    Modello/Gerarchia/piadina.cpp \
    Modello/Gerarchia/analcolico.cpp \
    Modello/Gerarchia/cocktail.cpp \
    Modello/Gerarchia/vino.cpp \
    Modello/json/jsoncpp.cpp \
    Modello/jsonio.cpp \
    Modello/model.cpp \
    Vista/main.cpp \
    Vista/controller.cpp \
    Vista/indexlayout.cpp \
    Vista/insertlayout.cpp \
    Vista/searchlayout.cpp \
    Vista/listinolayout.cpp \
    Vista/insertformexception.cpp

HEADERS += Qontainer/Qontainer.h \
    Modello/Gerarchia/prodotto.h \
    Modello/Gerarchia/cibo.h \
    Modello/Gerarchia/bevanda.h \
    Modello/Gerarchia/brioche.h \
    Modello/Gerarchia/panino.h \
    Modello/Gerarchia/piadina.h \
    Modello/Gerarchia/analcolico.h \
    Modello/Gerarchia/cocktail.h \
    Modello/Gerarchia/vino.h \
    Modello/Gerarchia/smartptr.h \
    Modello/json/json.h \
    Modello/jsonio.h \
    Modello/model.h \
    Vista/controller.h \
    Vista/indexlayout.h \
    Vista/insertlayout.h \
    Vista/searchlayout.h \
    Vista/listinolayout.h \
    Vista/insertformexception.h


FORMS += Vista/controller.ui

RESOURCES += resources.qrc
