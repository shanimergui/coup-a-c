#include "doctest.h"

#include "Contessa.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"

#include <iostream>

using namespace std;
using namespace coup;

TEST_CASE(" who  is the winner ")
{
    Game game_1{};
	Duke duke{game_1, "Samuel"};
	Assassin assassin{game_1, "david"};
	Ambassador ambassador{game_1, "shani"};
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador .income());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(ambassador.transfer(duke,ambassador));
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(duke.coup(ambassador)); 
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.coup(duke));
    CHECK_EQ(game_1.winner(),"david");

}

TEST_CASE(" small number of players ")
{
    Game game_1{};
    Duke duke(game_1, "Samuel");
    for(int i=0;i<15;i++)
    {
        CHECK_THROWS(duke.income());
        CHECK_THROWS(duke.foreign_aid());
        CHECK_THROWS(duke.income());

    }
   
}

TEST_CASE(" big number of players ")
{
    Game game_1{};
    Duke duke_1{game_1, "Samuel"};
	Assassin assassin_1{game_1, "david"};
	Ambassador ambassador_1{game_1, "shani"};
    Captain captin_1 {game_1, "Rephael"};
    Duke duke_2{game_1, "Gabi"};
	Assassin assassin_2{game_1, "Noa"};
	Ambassador ambassador_2{game_1, "Sara"};
    for(int i=0;i<20;i++)
    {
        CHECK_THROWS(duke_1.income());
        CHECK_THROWS(duke_2.foreign_aid());
        CHECK_NOTHROW(ambassador_1.transfer(duke_1,ambassador_1));
        CHECK_NOTHROW(ambassador_2.foreign_aid());
        CHECK_NOTHROW(duke_1.coup(ambassador_1)); 
        CHECK_NOTHROW(assassin_1.foreign_aid());
        CHECK_NOTHROW(assassin_2.income());
    }
   
}

TEST_CASE(" not is turn to play "){
    Game game_1{};
        Duke duke(game_1, "Samuel");
	    Assassin assassin{game_1, "david"};
	    Ambassador ambassador{game_1, "shani"};
	    Captain captain{game_1, "Rephael"};
	    Contessa contessa{game_1, "Gabi"};
        CHECK_THROWS(assassin.foreign_aid());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(captain.steal(duke));
        CHECK_THROWS(contessa.foreign_aid());
        duke.income();
        CHECK_THROWS(contessa.foreign_aid());
        CHECK_THROWS(ambassador.foreign_aid());
        CHECK_THROWS(captain.steal(duke));
}



