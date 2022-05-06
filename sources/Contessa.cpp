#include "Player.hpp"
#include "Contessa.hpp"
using namespace std;

namespace coup{
    void Contessa:: block(Player &other){
        sameGame(other);
        if(!other._alive){
            throw invalid_argument("Contessa cannot block dead player!");
        }
         if (other._role != "Assassin"){
            throw invalid_argument ("Contessa can block only Assassin!");
        }
        if (other._lastMove != "ascoup"){
            throw invalid_argument ("Contessa can block only Assassin's coup!");
        }
        if(other._turn_num == other._game->_turn){
            throw invalid_argument ("its already "+other._name+"'s "+other._role+" he can not be blocked anymore");
        }
         if( this->_who!= NULL)
        {
            throw invalid_argument ("contessa _who is Null!!!");
        }
        other._who->_alive = true;
        other._game->_num_of_players++;
    }
};