#ifndef CHESS_H
#define CHESS_H

#include <QtGui>
#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <iostream>
#include <QDebug>
#include <QGroupBox>
#include <typeinfo>
#include "pieces.h"

class Chess : public QWidget
{

    Q_OBJECT
public:
    Chess(QWidget *parent = 0);
    ~Chess();
    Pieces ***pPieces;
    Pieces *K1;
    Pieces *K2;
    Pieces *Buffor1;
    Pieces *Buffor2;
private:
    int player;
    QVBoxLayout *mainLay;
    bool start;
    int iBuffor;//bufor i
    int jBuffor;//bufor j
    ///////////////////////////
    void start_Window();
    QVBoxLayout *vLay;
    QDialog *dialog;
    QLabel *lChoose;
    QPushButton *bBegginer;
    QPushButton *bNormal;
    QPushButton *bExpert;
    ///////////////////////////

    ///////////////////////////
    void top();
    QGroupBox *topBox;
    QHBoxLayout *hLayTop;
    QLabel *lWho;
    QPushButton *bNewGame;
    QPushButton *bSettings;
    QPushButton *bQuit;
    ///////////////////////////
    void make_Board();
    QGroupBox *boardBox;
    QGridLayout* layout;
    QSignalMapper *signalMap;
    QPushButton ***bField;
    ///////////////////////////
    void start_Board();
    void connectAfterMove(int i, int j);
    ///////////////////////////
    bool p1RoszadaL;
    bool p1RoszadaP;
    bool p2RoszadaL;
    bool p2RoszadaP;
    ///////////////////////////
    bool check_Board(int owner);
public slots:
    void leftMouseButton(int a);
    void begginer();
    void normal();
    void expert();
    void newGame();
    void settings();
    void quit();
};

#endif // CHESS_H
