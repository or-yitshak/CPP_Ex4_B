
#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace coup{
    class Player;
    class Game
    {
    public:
        int _num_of_players = 0;
        int _turn = 0;
        bool _started;
        vector<Player*> _players;
        

    public:
        Game()
        {
            _num_of_players = 0;
            _turn = 0;
            _started = false;
        }
        string turn();
        vector<string> players();
        int num_of_players(){ return _num_of_players;}
        void add_player(Player &p);
        string winner();
        
    };
};