#ifndef PIECES_H
#define PIECES_H
#include <QPushButton>
#include <QString>
#include <typeinfo>

class Pieces : public QPushButton
{    
    Q_OBJECT
public:

    virtual ~Pieces(){}
    QPushButton* bPosition;
    bool activeOn;
////////////////
public:
    virtual void checkActive()=0;
    virtual bool checkMove(int x, int y, Pieces*** pPieces)=0;
    virtual bool checkMove(int x, int y, Pieces*** pPieces, bool roszadaL, bool roszadaP)=0;
    virtual bool checkCheck(int x, int y, Pieces*** pPieces)=0;
    int owner;
    int i;
    int j;
protected:
    int value;
private:

};

class King : public Pieces
{

public:
    explicit King(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces ***pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~King();
private:
};

class Queen : public Pieces
{

public:
    explicit Queen(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces ***pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~Queen();
private:
};

class Rook : public Pieces
{

public:
    explicit Rook(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces ***pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~Rook();
private:
};

class Bishop : public Pieces
{

public:
    explicit Bishop(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces*** pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~Bishop();
private:
};

class Knight : public Pieces
{

public:
    explicit Knight(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces ***pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~Knight();
private:
};

class Pawn : public Pieces
{

public:
    explicit Pawn(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces ***pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~Pawn();
private:
};
class None : public Pieces
{

public:
    explicit None(int player, int x, int y);

    void checkActive();
    bool checkMove(int x, int y, Pieces*** pPieces);
    bool checkMove(int x, int y, Pieces ***pPieces, bool roszadaL, bool roszadaP);
    bool nextPlayer(Pieces *pPieces);
    bool checkCheck(int x, int y, Pieces*** pPieces);
    ~None();
private:
};

#endif // PIECES_H

