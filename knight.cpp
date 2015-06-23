#include "pieces.h"

Knight::Knight(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 100;
    }
    else
    {
        value = -100;
    }
    i=x;
    j=y;
    activeOn=false;
    this->setText("N");

}

Knight::~Knight()
{
}

void Knight::checkActive()
{
    if(activeOn==false)
    {
        activeOn=true;
        this->setStyleSheet("background:#F0F000");
    }
    else
    {
        activeOn=false;
        this->setStyleSheet("background: transparent;");
    }
}

bool Knight::checkMove(int x, int y, Pieces*** pPieces)
{
    if(pPieces[x][y]->owner!=owner)
    {
        if(((x==i+1||x==i-1)&&(y==j+2||y==j-2))||((x==i+2||x==i-2)&&(y==j+1||y==j-1)))//Warunki ruchu Królowa
        {
            if(checkCheck(8, y, pPieces))
            {
                return false;
            }
        return true;
        }
    }
    return false;
}

bool Knight::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP){}

bool Knight::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
