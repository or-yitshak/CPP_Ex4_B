#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;

namespace coup
{
    void Assassin::coup(Player &other)
    {
        sameGame(other);
        startTurn();
        if(!other._alive){
            throw invalid_argument(other._name + "'s "+other._role+" is alredy dead!");
        }
        const int as_coup_price = 3;
        const int coup_price = 7;
        if (this->coins() < as_coup_price)
        {
            throw invalid_argument("Assassin dosent have enogh coins");
        }
        if (coup_price > this->coins() && this->coins() >= as_coup_price)
        {
            this->_coins -= as_coup_price;
            this->_who = &other;
            this->_lastMove = "ascoup";
        }
        if (coup_price <= this->coins())
        {
            this->_coins -= coup_price;
            this->_lastMove = "coup";
        }
        other._alive = false;
        other._game->_num_of_players--;
        endTurn();
    }
};