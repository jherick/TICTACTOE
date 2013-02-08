#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "Board.h"
#include <iostream>

class Game
{
    public:
        Game();
        virtual ~Game();
        void initialize();
        void update();
        void render ();
        void switchplayer();
        void run();
        bool checkwin();
        bool gameDraw();
        protected:
    private:
    player m_p1;
    player m_p2;
    player *m_currentPlayer;
    bool m_isComplete;
    Board m_board;
};

#endif // GAME_H
