#include "pieces.h"

Pawn::Pawn(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 34;
    }
    else
    {
        value = -34;
    }
    i=x;
    j=y;
    activeOn=false;
    this->setText("P");
}

Pawn::~Pawn()
{

}

void Pawn::checkActive()
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

bool Pawn::checkMove(int x, int y, Pieces*** pPieces)
{
    if(pPieces[x][y]->owner==0&&owner==1)
    {
        if((x==i&&y==j+1)||(j==1&&x==i&&y==j+2))//Warunki ruchu Królowa
        {
            if(y==j+2&&pPieces[x][2]->owner!=0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    if(pPieces[x][y]->owner==-1&&owner==1)
    {
        if((x==i+1||x==i-1)&&y==j+1)//Warunki ruchu Królowa
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(pPieces[x][y]->owner==0&&owner==-1)
    {
        if((x==i&&y==j-1)||(j==6&&x==i&&y==j-2))//Warunki ruchu Królowa
        {
            if(y==j-2&&pPieces[x][5]->owner!=0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    if(pPieces[x][y]->owner==1&&owner==-1)
    {
        if((x==i+1||x==i-1)&&y==j-1)//Warunki ruchu Królowa
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool Pawn::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP){}

bool Pawn::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
