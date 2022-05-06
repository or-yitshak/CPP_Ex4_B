#include "Player.hpp"
#include "Duke.hpp"
using namespace std;

namespace coup{
    void Duke:: block(Player &other){
        sameGame(other);
        if(!other._alive){
            throw invalid_argument("Duke cannot block dead player!");
        }
        if (other._lastMove != "foreign"){
            throw invalid_argument (this->_name+"'s Duke cannot block "+other._lastMove);
        }
        if(other._turn_num == other._game->_turn){
            throw invalid_argument ("its already "+other._name+"'s "+other._role+" he can not be blocked anymore");
        }
        other._coins-=2;
    }
    
    void Duke:: tax(){
        startTurn();
        moreThanTen();
        this->_coins+=3;   
        endTurn();

    }
};