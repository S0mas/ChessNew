#include "pieces.h"

Queen::Queen(int player, int x, int y)
{
    owner = player;
    if(owner>0)
    {
        value = 500;
    }
    else
    {
        value = -500;
    }
    i=x;
    j=y;
    activeOn=false;
    this->setText("Q");
}

Queen::~Queen()
{

}

void Queen::checkActive()
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

bool Queen::checkMove(int x,int y, Pieces*** pPieces)
{
    if((j==y||i==x)||(x-i==y-j||x-i==j-y))//Warunki ruchu Królowa
    {
        int c2 = j;
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
                return true;
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
                return true;
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
                return true;
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
                return true;
            }
        }
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

bool Queen::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP){}

bool Queen::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
