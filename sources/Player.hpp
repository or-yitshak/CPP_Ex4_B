#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Game.hpp"

using namespace std;


namespace coup{
    // class Game;
    class Player
    {
    public:
        int _coins=0;
        string _role;
        string _name;
        Game *_game;
        bool _alive;
        int _turn_num;
        string _lastMove;
        Player *_who;


    public:
        Player(Game &game, string name){
            _game = &game;  
            _name = name;
            _alive = true;
            _turn_num = this->_game->num_of_players();
            game.add_player(*this);
            _lastMove = "";
            _who = NULL;
        }

        void sameGame(Player &other) const;
        void moreThanTen();
        void startTurn()const;
        void endTurn()const;
        int coins(){return _coins;}
        string role(){return _role;}
        void income();
        void foreign_aid();
        void coup(Player &other);
    };
};