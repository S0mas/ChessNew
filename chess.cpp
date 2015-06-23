#include "chess.h"

Chess::Chess(QWidget *parent)
    : QWidget(parent)
{
    player = 1;
    p1RoszadaL = true;
    p1RoszadaP = true;
    p2RoszadaL = true;
    p2RoszadaP = true;
    start_Window();
    setWindowTitle(tr("Chess @ XXX"));
    mainLay = new QVBoxLayout (this);
    mainLay->setContentsMargins(0,0,0,0);
    setLayout(mainLay);
    top();
    start_Board();
    make_Board();
}
Chess::~Chess()
{
    for (int i = 0; i<8; i++)
    {
        delete [] pPieces[i];
    }
    delete [] pPieces;
    for (int i = 0; i<8; i++)
    {
        delete [] bField[i];
    }
    delete [] bField;
}


void Chess::start_Window()
{
    dialog = new QDialog (this);
    dialog->setWindowTitle(tr("Wybierz poziom"));
    lChoose = new QLabel ("Wybierz poziom:",dialog);
    vLay = new QVBoxLayout (dialog);
    bBegginer = new QPushButton ("Początkujący",dialog);
    bNormal = new QPushButton ("Normalny",dialog);
    bExpert = new QPushButton ("Ekspert",dialog);

    connect(bBegginer, SIGNAL(clicked()), this, SLOT(begginer()));
    connect(bBegginer, SIGNAL(clicked()), dialog, SLOT(accept()));
    connect(bNormal, SIGNAL(clicked()), this, SLOT(normal()));
    connect(bNormal, SIGNAL(clicked()), dialog, SLOT(accept()));
    connect(bExpert, SIGNAL(clicked()), this, SLOT(expert()));
    connect(bExpert, SIGNAL(clicked()), dialog, SLOT(accept()));

    vLay->addWidget(lChoose);
    vLay->addWidget(bBegginer);
    vLay->addWidget(bNormal);
    vLay->addWidget(bExpert);
    vLay->setContentsMargins(50,10,50,20);
    dialog->setLayout(vLay);
    dialog->exec();
}
void Chess::top()
{
    topBox = new QGroupBox(this);
    topBox->setContentsMargins(0,0,0,0);
    hLayTop = new QHBoxLayout(this);
    bNewGame=new QPushButton("Nowa Gra",this);
    bNewGame->setMinimumSize(60,30);
    bSettings=new QPushButton("Ustawienia",this);
    bSettings->setMinimumSize(40,30);
    bQuit=new QPushButton("Zakoncz",this);
    bQuit->setMinimumSize(40,30);
    hLayTop->addWidget(bNewGame);
    hLayTop->addWidget(bSettings);
    hLayTop->addWidget(bQuit);
    connect(bNewGame, SIGNAL(clicked()),this, SLOT(newGame()));
    connect(bSettings, SIGNAL(clicked()), this, SLOT(settings()));
    connect(bQuit, SIGNAL(clicked()),this, SLOT(quit()));
    lWho = new QLabel(tr("Gracz: %1").arg(player), this);
    lWho->setGeometry(0,0,70,10);
    hLayTop->addWidget(lWho);
    topBox->setLayout(hLayTop);
    mainLay->addWidget(topBox);
}

void Chess::make_Board()
{
    boardBox = new QGroupBox(this);
    layout = new QGridLayout(this);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->setSpacing(0);
    signalMap = new QSignalMapper(this);
    try
    {
        bField = new QPushButton **[8];
        for (int i = 0; i < 8; i++)
        {
            bField[i] = new QPushButton *[8];
            for(int j=0; j<8; j++)
            {
                bField[i][j]= new QPushButton(this);
                bField[i][j]->setText("");
                bField[i][j]->setMinimumSize(60,60);
                bField[i][j]->setMaximumSize(60,60);
                if((i%2==1&&j%2==0)||(i%2==0&&j%2==1))
                {
                    bField[i][j]->setStyleSheet("background:#000");
                }
                else
                {
                    bField[i][j]->setStyleSheet("background:#FFF");
                }
                layout->addWidget(bField[i][j],j,i,1,1);

            }
        }
    }

    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }
    connect(signalMap, SIGNAL(mapped(int)), this, SLOT(leftMouseButton(int)));
    try
    {
        for (int i = 0; i < 8; i++)
        {
            for(int j=0; j<8; j++)
            {
                pPieces[i][j]->setMinimumSize(60,60);
                pPieces[i][j]->setMaximumSize(60,60);
                pPieces[i][j]->setStyleSheet("background: transparent;");
                layout->addWidget(pPieces[i][j],j,i,1,1);
                connect(pPieces[i][j], SIGNAL(clicked()), signalMap, SLOT(map()));
                int x = i * 10 + j;
                signalMap->setMapping(pPieces[i][j], x);
            }
        }
    }
    catch (std::bad_alloc& ba)
    {
        std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    }

    boardBox->setLayout(layout);
    mainLay->addWidget(boardBox,1,Qt::AlignCenter);
}

void Chess::start_Board()
{
    iBuffor = 0;
    jBuffor = 0;
    pPieces = new Pieces **[8];
    for (int i = 0; i < 8; i++)
    {
        pPieces[i] = new Pieces *[8];
    }
////////////////////////////////////////////Player 1(1)
    K1 = new King (1, 3, 0);
    pPieces[0][0]= new Rook (1, 0, 0);
    pPieces[1][0]= new Knight (1, 1, 0);
    pPieces[2][0]= new Bishop (1, 2, 0);
    pPieces[3][0]= K1;
    pPieces[4][0]= new Queen(1, 4, 0);
    pPieces[5][0]= new Bishop (1, 5, 0);
    pPieces[6][0]= new Knight (1, 6, 0);
    pPieces[7][0]= new Rook (1, 7, 0);
    pPieces[0][1]= new Pawn (1, 0, 1);
    pPieces[1][1]= new Pawn (1, 1, 1);
    pPieces[2][1]= new Pawn (1, 2, 1);
    pPieces[3][1]= new Pawn (1, 3, 1);
    pPieces[4][1]= new Pawn (1, 4, 1);
    pPieces[5][1]= new Pawn (1, 5, 1);
    pPieces[6][1]= new Pawn (1, 6, 1);
    pPieces[7][1]= new Pawn (1, 7, 1);
//////////////////////////////////////////Player 2(-1)
    K2 = new King (-1, 3, 7);
    pPieces[0][7]= new Rook (-1, 0, 7);
    pPieces[1][7]= new Knight (-1, 1, 7);
    pPieces[2][7]= new Bishop (-1, 2, 7);
    pPieces[3][7]= K2;
    pPieces[4][7]= new Queen(-1, 4, 7);
    pPieces[5][7]= new Bishop (-1, 5, 7);
    pPieces[6][7]= new Knight (-1, 6, 7);
    pPieces[7][7]= new Rook (-1, 7, 7);
    pPieces[0][6]= new Pawn (-1, 0, 6);
    pPieces[1][6]= new Pawn (-1, 1, 6);
    pPieces[2][6]= new Pawn (-1, 2, 6);
    pPieces[3][6]= new Pawn (-1, 3, 6);
    pPieces[4][6]= new Pawn (-1, 4, 6);
    pPieces[5][6]= new Pawn (-1, 5, 6);
    pPieces[6][6]= new Pawn (-1, 6, 6);
    pPieces[7][6]= new Pawn (-1, 7, 6);
 //////////////////////////////////////////None
    for(int i = 0; i < 8; i++)
    {
        for(int j = 2; j < 6; j++)
        {
            pPieces[i][j] = new None(0, i, j);
        }
    }
}
bool Chess::check_Board(int owner){}
/*{
    for(int i = 0; i > 8; i++)
    {
        for(int j = 0; j > 8; j++)
        {
            if(pPieces[i][j]->checkCheck(pPieces)&&pPieces[i][j]->owner==owner)
            {
                return true;
            }
        }
    }
    return false;
}*/

void Chess::leftMouseButton(int a)/////////////DO OGARNIECIA
{
    int x, y;
    x=a/10;
    y=a%10;
    int c=iBuffor;
    int d=jBuffor;
    if(pPieces[x][y]->activeOn)
    {
        pPieces[x][y]->checkActive();
        return;
    }
    if(pPieces[c][d]->activeOn&&pPieces[c][d]->owner==player)
    {
        pPieces[c][d]->checkActive();
        if(typeid(*pPieces[c][d]) == typeid(King))
        {
            if(pPieces[c][d]->owner==1)
            {
                if(pPieces[c][d]->checkMove(x,y,pPieces,p1RoszadaL,p1RoszadaP))
                {
                    player = -1;
                    delete pPieces[x][y];
                    pPieces[x][y] = K1;
                    connectAfterMove(x,y);
                    p1RoszadaL = false;
                    p1RoszadaP = false;
                    delete pPieces[c][d];
                    pPieces[c][d] = new None(0, c, d);
                    connectAfterMove(c,d);
                    if(c==3&&d==0&&(x==1||x==5))
                    {
                        if(x==1)
                        {
                            delete pPieces[0][0];
                            delete pPieces[2][0];
                            pPieces[0][0] = new None(0, 0, 0);
                            pPieces[2][0] = new Rook(1, 2, 0);
                            connectAfterMove(0,0);
                            connectAfterMove(2,0);
                        }
                        if(x==5)
                        {
                            delete pPieces[4][0];
                            delete pPieces[7][0];
                            pPieces[4][0] = new Rook(1, 4, 0);
                            pPieces[7][0] = new None(0, 7, 0);
                            connectAfterMove(4,0);
                            connectAfterMove(7,0);
                        }
                    }
                }
            }
            if(pPieces[c][d]->owner==-1)
            {
                if(pPieces[c][d]->checkMove(x,y,pPieces,p2RoszadaL,p2RoszadaP))
                {
                    player = 1;
                    delete pPieces[x][y];
                    pPieces[x][y] = K2;
                    p2RoszadaL = false;
                    p2RoszadaP = false;
                    connectAfterMove(x,y);
                    delete pPieces[c][d];
                    pPieces[c][d] = new None(0, c, d);
                    connectAfterMove(c,d);
                    if(c==3&&d==7&&(x==1||x==5))
                    {
                        if(x==1)
                        {
                            delete pPieces[0][7];
                            delete pPieces[2][7];
                            pPieces[0][7] = new None(0, 0, 7);
                            pPieces[2][7] = new Rook(-1, 2, 7);
                            connectAfterMove(0,7);
                            connectAfterMove(2,7);
                        }
                        if(x==5)
                        {
                            delete pPieces[4][7];
                            delete pPieces[7][7];
                            pPieces[4][7] = new Rook(-1, 4, 7);
                            pPieces[7][7] = new None(0, 7, 7);
                            connectAfterMove(4,7);
                            connectAfterMove(7,7);
                        }

                    }

                }
            }
        }
        else if(pPieces[c][d]->checkMove(x,y,pPieces))
        {
            if(typeid(*pPieces[x][y]) == typeid(Queen))
            {
                Buffor1 = new Queen(pPieces[x][y]->owner, x, y);
                delete pPieces[x][y];
            }
            if(typeid(*pPieces[x][y]) == typeid(Bishop))
            {
                Buffor1 = new Bishop(pPieces[x][y]->owner, x, y);
                delete pPieces[x][y];
            }
            if(typeid(*pPieces[x][y]) == typeid(Knight))
            {
                Buffor1 = new Knight(pPieces[x][y]->owner, x, y);
                delete pPieces[x][y];
            }
            if(typeid(*pPieces[x][y]) == typeid(Rook))
            {
                Buffor1 = new Rook(pPieces[x][y]->owner, x, y);
                delete pPieces[x][y];
            }
            if(typeid(*pPieces[x][y]) == typeid(Pawn))
            {
                Buffor1 = new Pawn(pPieces[x][y]->owner, x, y);
                delete pPieces[x][y];
            }

            if(typeid(*pPieces[c][d]) == typeid(Queen))
            {
                pPieces[x][y] = new Queen(pPieces[c][d]->owner, x, y);
                Buffor2 = new Queen(pPieces[c][d]->owner, c, d);
            }
            if(typeid(*pPieces[c][d]) == typeid(Bishop))
            {
                pPieces[x][y] = new Bishop(pPieces[c][d]->owner, x, y);
                Buffor2 = new Bishop(pPieces[c][d]->owner, c, d);
            }
            if(typeid(*pPieces[c][d]) == typeid(Knight))
            {
                pPieces[x][y] = new Knight(pPieces[c][d]->owner, x, y);
                Buffor2 = new Knight(pPieces[c][d]->owner, c, d);
            }
            if(typeid(*pPieces[c][d]) == typeid(Rook))
            {
                pPieces[x][y] = new Rook(pPieces[c][d]->owner, x, y);
                Buffor2 = new Rook(pPieces[c][d]->owner, c, d);
                if(pPieces[c][d]->owner==1)
                {
                    if(c==0)
                    {
                        p1RoszadaL = false;
                    }
                    if(c==7)
                    {
                        p1RoszadaP = false;
                    }
                }
                if(pPieces[c][d]->owner==-1)
                {
                    if(c==0)
                    {
                        p2RoszadaL = false;
                    }
                    if(c==7)
                    {
                        p2RoszadaP = false;
                    }
                }
            }
            if(typeid(*pPieces[c][d]) == typeid(Pawn))
            {
                pPieces[x][y] = new Pawn(pPieces[c][d]->owner, x, y);
                Buffor2 = new Pawn(pPieces[c][d]->owner, c, d);
            }

            if(pPieces[c][d]->owner==1)
            {
                delete pPieces[c][d];
                pPieces[c][d] = new None(0, c, d);
                if(K1->checkCheck(8,0,pPieces))
                {
                    //delete pPieces[x][y];
                    delete pPieces[c][d];
                    //pPieces[x][y]=Buffor1;
                    pPieces[c][d]=Buffor2;
                    //connectAfterMove(x,y);
                    connectAfterMove(c,d);
                    return;////// Do OGARNIECIA
                }
            }
            if(pPieces[c][d]->owner==-1)
            {
                delete pPieces[c][d];
                pPieces[c][d] = new None(0, c, d);
                if(K2->checkCheck(8,0,pPieces))
                {
                    delete pPieces[x][y];
                    delete pPieces[c][d];
                    pPieces[x][y]=new None(0, x, y);
                    pPieces[c][d]=new Pawn(-1, c, d);
                    connectAfterMove(x,y);
                    connectAfterMove(c,d);
                    return;///////Do ogarniecia
                }
            }
            player = -player;
            connectAfterMove(x,y);
            connectAfterMove(c,d);
        }
        return;
    }
    if(pPieces[c][d]->activeOn==false)
    {
        if(pPieces[x][y]->activeOn==false)
        {
            pPieces[x][y]->checkActive();
            iBuffor=x;
            jBuffor=y;
        }
    }
}

void Chess::connectAfterMove(int i, int j)
{
    pPieces[i][j]->setMinimumSize(60,60);
    pPieces[i][j]->setMaximumSize(60,60);
    pPieces[i][j]->setStyleSheet("background: transparent;");
    layout->addWidget(pPieces[i][j],j,i,1,1);
    connect(pPieces[i][j], SIGNAL(clicked()), signalMap, SLOT(map()));
    int x = i * 10 + j;
    signalMap->setMapping(pPieces[i][j], x);
}
void Chess::begginer()
{

}
void Chess::normal()
{

}
void Chess::expert()
{

}
void Chess::newGame()
{

}
void Chess::settings()
{

}
void Chess::quit()
{
    close();
}
