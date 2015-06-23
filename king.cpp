#include "pieces.h"

King::King(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 2000;
    }
    else
    {
        value = -2000;
    }
    i=x;
    j=y;
    activeOn = false;
    this->setText("K");
}

King::~King()
{
}

void King::checkActive()
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

bool King::checkMove(int x, int y, Pieces*** pPieces)
{
    return false;
}

bool King::checkMove(int x, int y, Pieces*** pPieces, bool roszadaL, bool roszadaP)
{
    if(pPieces[x][y]->owner!=owner)
    {
        if((i==x+1||i==x||i==x-1)&&(j==y+1||j==y||j==y-1))//Warunki ruchu Królem
        {
            if(checkCheck(x, y, pPieces))
            {
                return false;
            }
            return true;
        }
        if(((i==x+2&&roszadaL==true)||(i==x-2&&roszadaP==true))&&(j==y))
        {
            if(typeid(*pPieces[7][0])==typeid(Rook)&&pPieces[7][0]->owner==owner&&x==5)
            {
                for(int c = 4; c<7; c++)
                {
                    if(pPieces[c][0]->owner!=0)
                    {
                        return false;
                    }
                    if(pPieces[c][0]->owner==0)
                    {
                        if(checkCheck(c, 0, pPieces))
                        {
                            return false;
                        }
                    }
                }
            }
            if(typeid(*pPieces[0][0])==typeid(Rook)&&pPieces[0][0]->owner==owner&&x==1)
            {
                for(int c = 1; c<3; c++)
                {
                    if(pPieces[c][0]->owner!=0)
                    {
                        return false;
                    }
                    if(pPieces[c][0]->owner==0)
                    {
                        if(checkCheck(c, 0, pPieces))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool King::checkCheck(int x, int y, Pieces*** pPieces)
{
    for(int a = 6; a < 8; a++)
    {
        for(int b = 3; b < 8; b++)
        {
            if(x<8)
            {
                if(pPieces[a][b]->owner!=owner&&pPieces[a][b]->owner!=0&&pPieces[a][b]->checkMove(x, y, pPieces)&&typeid(*pPieces[a][b])!=typeid(Pawn))
                {
                    return true;
                }
                if(pPieces[a][b]->owner!=owner&&pPieces[a][b]->owner!=0&&(typeid(*pPieces[a][b])==typeid(Pawn))&&(pPieces[a][b]->i==x+1||pPieces[a][b]->i==x-1)&&(pPieces[a][b]->j==y+owner))
                {
                    return true;
                }
            }
            else
            {
                if(pPieces[a][b]->owner!=owner&&pPieces[a][b]->owner!=0&&pPieces[a][b]->checkMove(i, j, pPieces)&&typeid(*pPieces[a][b])!=typeid(Pawn))
                {
                    return true;
                }
                if(pPieces[a][b]->owner!=owner&&pPieces[a][b]->owner!=0&&(typeid(*pPieces[a][b])==typeid(Pawn))&&(pPieces[a][b]->i==i+1||pPieces[a][b]->i==i-1)&&(pPieces[a][b]->j==j+owner))
                {
                    return true;
                }
            }
        }
    }
    return false;
}
