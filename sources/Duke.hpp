#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Duke: public Player
    {
    private:
        

    public:
        Duke(Game &game, string name): Player(game, name){
            this->_role = "Duke";
        }
        void block(Player &other);
        void tax();
    };
};