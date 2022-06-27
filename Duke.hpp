#include "Player.hpp"
namespace coup {

class Duke : public Player {
    public:
        Duke(Game& game, std::string name);
        void tax();
        void block(Player& player);
        std::string role() const override;
        friend class Tax;
};
}