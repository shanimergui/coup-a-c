#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "Player.hpp"

namespace coup {
    class Player;

    class Game {
        private:
            size_t turn_index;
            bool is_running;
            std::vector<Player*> m_players;
            void add_player(Player& player);
            size_t count_active_players() const;
            void switch_to_next_turn();
            bool can_player_play(Player* player);
        public:
            Game();
            std::vector<std::string> players() const;
            std::string turn() const;
            std::string winner() const;
    
            friend class Player;
    };

    class Action {
        public:
            virtual void execute(Player* player) = 0;
            virtual void undo(Player* blocker, Player* blocked) = 0;
            virtual ~Action();
    };

    class Income : public Action { 
        public:
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class ForeignAid : public Action {
        public:
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class Coup : public Action {
        private:
            Player* player_to_kill;
        public:
            Coup(Player* player_to_kill);
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class Tax : public Action {
        public:
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class AssassinCoup : public Action {
        private:
            Player* player_to_kill;
        public:
            AssassinCoup(Player* player_to_kill);
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class Transfer : public Action {
        private:
            Player* from;
            Player* to;
        public:
            Transfer(Player* from, Player* to);
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };

    class Steal : public Action {
        private: 
            Player* from;
        public:
            Steal(Player* from);
            void execute(Player* player) override;
            void undo(Player* blocker, Player* blocked) override;
    };


}

#endif