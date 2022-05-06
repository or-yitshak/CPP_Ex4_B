#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Contessa: public Player
    {
    private:
        

    public:
        Contessa(Game &game, string name): Player(game, name){
            this->_role = "Contessa";
        }
        void block(Player &other);      
    };
};