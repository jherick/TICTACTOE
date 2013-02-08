#include "Game.h"
#include "player.h"
#include "Board.h"
Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::initialize (){
    m_board.initialize();
    m_p1.setname("Jherick");
    m_p1.seticon('O');
    m_p2.setname("Arian");
    m_p2.seticon('X');
    m_currentPlayer = &m_p1;
}

void Game::update (){
        m_board.update(m_currentPlayer->getmove(), m_currentPlayer->geticon());
        m_isComplete = checkwin();
        if (m_isComplete == 1){
            m_board.render();
            cout << "****************************************************************************";
            cout << "\n\t\t The winner is " << m_currentPlayer->getname()<<endl;
            cout << "****************************************************************************" << endl;
        }
        if (gameDraw() == 1 && m_isComplete == 0){
            m_board.render();
            cout << "****************************************************************************";
            cout << "\n\t\t GAME DRAW "<<endl;
            cout << "****************************************************************************" << endl;
        }
        switchplayer();
}

void Game::render (){
    m_board.render();
    cout << "\t\tIt is the turn of " << m_currentPlayer->getname();
    }


void Game::switchplayer(){
    if (m_currentPlayer == &m_p1)
        m_currentPlayer = &m_p2;
    else if (m_currentPlayer == &m_p2)
        m_currentPlayer = &m_p1;
}

void Game::run(){
    while(m_isComplete == 0 && gameDraw() == 0){
    render();
    update();
}
}

bool Game::checkwin (){
    m_board.checkwin();
}

bool Game::gameDraw(){
    m_board.gameDraw();
}
