#include "Assassin.hpp"

using namespace coup;

Assassin::Assassin(Game& game, std::string name) : Player(game, name) {}

void Assassin::coup(Player& player) {
    this->verify_can_play();
    delete this->last_action;
    this->last_action = new AssassinCoup(&player);
    this->last_action->execute(this);
    this->end_move();
}

std::string Assassin::role() const {
    return "Assassin";
}