#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    string Game::turn()
    {
        string ans;
        for (Player *p : this->_players)
        {
            if(p->_turn_num == this->_turn){
                ans = p->_name;
                break;
            }
        }
        return ans;
    }

    vector<string> Game::players()
    {
        vector<string> names;
        for (Player *p : this->_players)
        {
            if(p->_alive){
                names.push_back(p->_name);
            }
        }       
        return names;
    }
    
    void Game:: add_player(Player &p){
        if (this->_started){
            throw invalid_argument("the game has already started new players cannot be added!");
        }
        const int max_players = 6;
        if(this->_players.size()>= max_players){
            throw invalid_argument ("too many players!");
        }
        this->_players.push_back(&p);
        this->_num_of_players++;
        // if(this->_players.size() == 2){
        //     this->_started = true;
        // }           
    }

    string Game:: winner(){
        if(!this->_started){
            throw invalid_argument("the gmae has not started yet!");
        }
        if(this->num_of_players() != 1){
            throw invalid_argument("the gmae is not over!");
        }
        string winner;
        for (Player *p : this->_players){
            if (p->_alive){
                winner = p->_name;
                break;
            }
        }
        return winner;
    }
};