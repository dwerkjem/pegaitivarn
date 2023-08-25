#include <vector>


namespace casino_dealer{

struct Player { 
    int entity_id;
    int bet;
}

class Dealer { 
  private:
    int _token = 0;
    int _bet = 0;
    int _max_players = 4;
    Game _game;
    std::vector<Player> _players;
  public:
    void playerJoin (int entity_id){

    };
    void playerBet (int entity_id, int token){

    };
    void playerLeave (int entity_id){

    };

};

}
