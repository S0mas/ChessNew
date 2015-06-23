#include "pieces.h"
#include <typeinfo>

Bishop::Bishop(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 105;     
    }
    else
    {
        value = -105;
    }
    i=x;
    j=y;
    activeOn=false;
    this->setText("B");
}

Bishop::~Bishop()
{
}

void Bishop::checkActive()
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

bool Bishop::checkMove(int x, int y, Pieces ***pPieces)
{
    int c2 = j;
    if(x-i==y-j||x-i==j-y)//Warunki ruchu Królowa
    {
        if(x>i&&y>j)
        {
            for(int c1 = i+1; c1<=x; c1++)
            {
                c2 = c2 + 1;
                if(c2!=y&&pPieces[c1][c2]->owner!=0)
                {
                    return false;
                }
                if(c2==y&&pPieces[x][y]->owner==pPieces[i][j]->owner)
                {
                    return false;
                }
            }
        }
        if(x<i&&y>j)
        {
            for(int c1 = i-1; c1>=x; c1--)
            {
                c2 = c2 + 1;
                if(c2!=y&&pPieces[c1][c2]->owner!=0)
                {
                    return false;
                }
                if(c2==y&&pPieces[x][y]->owner==pPieces[i][j]->owner)
                {
                    return false;
                }
            }
        }
        if(x>i&&y<j)
        {
            for(int c1 = i+1; c1<=x; c1++)
            {
                c2 = c2 - 1;
                if(c2!=y&&pPieces[c1][c2]->owner!=0)
                {
                    return false;
                }
                if(c2==y&&pPieces[x][y]->owner==pPieces[i][j]->owner)
                {
                    return false;
                }
            }
        }
        if(x<i&&y<j)
        {
            for(int c1 = i-1; c1>=x; c1--)
            {
                c2 = c2 - 1;
                if(c2!=y&&pPieces[c1][c2]->owner!=0)
                {
                    return false;
                }
                if(c2==y&&pPieces[x][y]->owner==pPieces[i][j]->owner)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool Bishop::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP){}

bool Bishop::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
/*{
    int c2 = j;
    for(int c1 = i+1; c1<=7; c1++)
    {
        c2 = c2 + 1;
        if(c2>7)
        {
            break;
        }
        if(pPieces[c1][c2]->owner==owner||(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])!=typeid(King)))
        {
            break;
        }
        if(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])==typeid(King))
        {
            return true;
        }
    }
    c2 = j;
    for(int c1 = i+1; c1<=7; c1++)
    {
        c2 = c2 - 1;
        if(c2<0)
        {
            break;
        }
        if(pPieces[c1][c2]->owner==owner||(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])!=typeid(King)))
        {
            break;
        }
        if(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])==typeid(King))
        {
            return true;
        }
    }
    c2 = j;
    for(int c1 = i-1; c1>=0; c1--)
    {
        c2 = c2 + 1;
        if(c2>7)
        {
            break;
        }
        if(pPieces[c1][c2]->owner==owner||(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])!=typeid(King)))
        {
            break;
        }
        if(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])==typeid(King))
        {
            return true;
        }
    }
    c2 = j;
    for(int c1 = i-1; c1>=0; c1--)
    {
        c2 = c2 - 1;
        if(c2<0)
        {
            break;
        }
        if(pPieces[c1][c2]->owner==owner||(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])!=typeid(King)))
        {
            break;
        }
        if(pPieces[c1][c2]->owner==-owner&&typeid(*pPieces[c1][c2])==typeid(King))
        {
            return true;
        }
    }
    return false;
}*/
