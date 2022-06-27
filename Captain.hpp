#include "Player.hpp"

namespace coup { 

class Captain : public Player {
    public:
        Captain(Game& game, std::string name);
        void steal(Player& from);
        void block(Player& player);
        std::string role() const override;
};
}