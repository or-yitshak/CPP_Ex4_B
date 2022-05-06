#include "Player.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup{
    void Captain:: block(Player &other){
        sameGame(other);
        if(!other._alive){
            throw invalid_argument("Captain cannot block dead player!");
        }
         if (other._role != "Captain"){
            throw invalid_argument ("Captain can block only Captain!");
        }
         if (other._lastMove != "steal"){
            throw invalid_argument ("Captain can block only Captain's steal!");
        }
        if(other._turn_num == other._game->_turn){
            throw invalid_argument ("its already "+other._name+"'s "+other._role+" he can not be blocked anymore");
        }
        if(other._who == NULL)
        {
            throw invalid_argument ("captains _who is Null!!!");
        }
        other._coins -= 2;
        other._who->_coins += 2;     
    }
    void Captain:: steal(Player &other){
        sameGame(other);
        startTurn();
        moreThanTen();
        if(!other._alive){
            throw invalid_argument("Captain cannot steal from dead player!");
        }
        // if(other.coins() <2){
        //     throw invalid_argument ("this player dont have enogh coins to steal!");
        // }
        if(other.coins() >= 2){
            other._coins -= 2 ;
            this->_coins += 2;
        }
        else if(other.coins() == 1){
            other._coins -= 1 ;
            this->_coins += 1;
        }
        // other._coins -= 2 ;
        // this->_coins += 2;
        this->_lastMove = "steal";
        this->_who = &other;
        endTurn();
    }
};