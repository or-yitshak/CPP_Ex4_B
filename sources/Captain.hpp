#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Captain: public Player
    {
    public:
        

    public:
        Captain(Game &game, string name): Player(game, name){
            this->_role = "Captain";
        }
        void block(Player &other);
        void steal(Player &other);
    };
};