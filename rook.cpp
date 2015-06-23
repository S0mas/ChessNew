#include "pieces.h"

Rook::Rook(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 160;
    }
    else
    {
        value = -160;
    }
    i=x;
    j=y;
    activeOn=false;
    this->setText("R");
}

Rook::~Rook()
{

}

void Rook::checkActive()
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

bool Rook::checkMove(int x, int y, Pieces*** pPieces)
{

    if(y==j||x==i)//Warunki ruchu wieza
    {
        if(y==j)
        {
            if(x>i)
            {
                for(int c = i+1; c<=x; c++)
                {
                    if(c!=x&&pPieces[c][y]->owner!=0)
                    {
                        return false;
                    }
                    if(c==x&&pPieces[c][y]->owner==pPieces[i][j]->owner)
                    {
                        return false;
                    }
                }
                return true;
            }
            if(x<i)
            {
                for(int c = i-1; c>=x; c--)
                {
                    if(c!=x&&pPieces[c][y]->owner!=0)
                    {
                        return false;
                    }
                    if(c==x&&pPieces[c][y]->owner==pPieces[i][j]->owner)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        if(x==i)
        {
            if(y>j)
            {
                for(int c = j+1; c<=y; c++)
                {
                    if(c!=y&&pPieces[x][c]->owner!=0)
                    {
                        return false;
                    }
                    if(c==y&&pPieces[x][c]->owner==pPieces[i][j]->owner)
                    {
                        return false;
                    }
                }
                return true;
            }
            if(y<j)
            {
                for(int c = j-1; c>=y; c--)
                {
                    if(c!=y&&pPieces[x][c]->owner!=0)
                    {
                        return false;
                    }
                    if(c==y&&pPieces[x][c]->owner==pPieces[i][j]->owner)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

bool Rook::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP){}

bool Rook::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
