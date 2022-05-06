#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{
    void Player::sameGame(Player &other)const
    {
        if (this->_game != other._game){
            throw invalid_argument (other._name+"'s "+other._role+" is from a different game!");
        }
    }
    void Player::moreThanTen()
    {
        const int must_coup = 10;
        if(this->coins()>=must_coup){
            throw invalid_argument (this->_name+"'s " + this->_role+ " have more than 10 coins he must do coup!");
        }
    }
    void Player:: startTurn()const
    {
        if(this->_game->num_of_players() == 1)
        {
            throw invalid_argument ("the game is over!");
        }
        if(!this->_alive)
        {
            throw invalid_argument (this->_name+"'s " + this->_role+" is dead!");
        }
        if(this->_turn_num != this->_game->_turn)
        {
            throw invalid_argument ("its not "+this->_name+"'s " + this->_role+ " turn to play");
        }  
    }
    void Player::endTurn()const
    {
        this->_game->_turn++;
        this->_game->_turn %= this->_game->_players.size();
        size_t i = (size_t)this->_game->_turn;
        while(!this->_game->_players.at(i)->_alive){
            this->_game->_turn++;
            this->_game->_turn %= this->_game->_players.size();
            i++;
            i %= this->_game->_players.size();
        }
        if(!this->_game->_started){
            this->_game->_started = true;
        }
    }
    void Player::income()
    {
        startTurn();
        moreThanTen();
        _coins++;
        _lastMove = "income";
        endTurn();       
    }

    void Player:: foreign_aid()
    {
        startTurn();
        moreThanTen();
        _coins+=2;
        _lastMove = "foreign";
        endTurn();
    }

    void Player:: coup(Player &other)
    { 
        sameGame(other);
        startTurn();
        if(!other._alive){
            throw invalid_argument(other._name + "'s "+other._role+" is alredy dead!");
        }
        const int coup_price = 7;
        if (this->coins()<coup_price){
            throw invalid_argument(this->_name + " dont have enogh coins to do coup");
        }
        this->_coins -= coup_price;
        other._alive = false;
        other._game->_num_of_players--;
        _lastMove = "coup";
        endTurn();
    }
   
    
};