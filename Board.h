#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Board
{
    public:
        Board();
        virtual ~Board();
        void initialize();
        void render();
        void update(int move,char icon);
        bool checkwin();
        bool gameDraw();
    protected:
    private:
    char box[9];

};

#endif // BOARD_H
