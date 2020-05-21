#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <random>
#include <utility> 
#include <functional>
#include <memory>

#include "character.h"

class game
{
private:
	
	std::unique_ptr<character> first_player;
	std::unique_ptr<character> second_player;
	std::shared_ptr<int> rounds;
	
	std::unique_ptr<int> first = std::make_unique<int>(1);
	
	std::unique_ptr<bool> gameover = std::make_unique<bool>(true);

	void switch_roles();

	void isAttacking_first(std::unique_ptr<character> const& f_orderus, std::unique_ptr<character> const& f_beast);


public:

	game(std::unique_ptr<character> & c_player, std::unique_ptr<character> & c_beast, const int rounds);

	void run();

};


#endif // !_GAME_H
