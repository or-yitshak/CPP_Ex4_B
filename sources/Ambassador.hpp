#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Ambassador: public Player
    {
    private:
        

    public:
        Ambassador(Game &game, string name): Player(game, name){
            this->_role = "Ambassador";
        }
        void block(Player &other);
        void transfer(Player &p1, Player &p2);
    };
};