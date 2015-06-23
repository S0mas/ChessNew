#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T13:44:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChessNew
TEMPLATE = app


SOURCES += main.cpp\
        chess.cpp \
    king.cpp \
    rook.cpp \
    knight.cpp \
    bishop.cpp \
    pawn.cpp \
    queen.cpp \
    none.cpp

HEADERS  += chess.h \
    pieces.h
