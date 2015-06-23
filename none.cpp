#include "pieces.h"

None::None(int player, int x, int y)
{
    owner = player;
    value = 0;
    i=x;
    j=y;
    activeOn = false;
    this->setText("");
}

None::~None()
{

}

void None::checkActive()
{

}

bool None::checkMove(int x, int y, Pieces ***pPieces)
{
    return false;
}

bool None::checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP)
{
    return false;
}
bool None::checkCheck(int x, int y, Pieces*** pPieces)
{
    return false;
}
