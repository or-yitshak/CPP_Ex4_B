#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup{
    void Ambassador:: block(Player &other){
        sameGame(other);
        if(!other._alive){
            throw invalid_argument("Ambassador cannot block dead player!");
        }
        if (other._role != "Captain"){
            throw invalid_argument ("Ambassador can block only Captain!");
        }
        if (other._lastMove != "steal"){
            throw invalid_argument ("Ambassador can block only steal!");
        }
        if(other._turn_num == other._game->_turn){
            throw invalid_argument ("its already "+other._name+"'s "+other._role+" he can not be blocked anymore");
        }
        if(other._who == NULL)
        {
            throw invalid_argument ("Ambassador: _who is Null!!!");
        }
        other._coins -= 2;
        other._who->_coins += 2;          
    }

    void Ambassador:: transfer(Player &p1, Player &p2){
        if (this->_game != p1._game || this->_game != p2._game){
            throw invalid_argument ("one of the players is from a different game!");
        }
        startTurn();
        if(!p1._alive || !p2._alive){
            throw invalid_argument("cannot transfer between dead players!");
        }
        moreThanTen();
        if(p1._coins <= 0){
            throw invalid_argument ("cannot make this move");
        }
        p1._coins--;
        p2._coins++;
        this->_lastMove = "transfer";
        endTurn();
    }
};