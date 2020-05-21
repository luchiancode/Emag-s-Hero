#include <iostream>
#include <random>
#include <functional>
#include <memory>
#include <vector>
#include <numeric>
#include <typeinfo>


#include "game.h"


game::game(std::unique_ptr<character> & c_player, std::unique_ptr<character> & c_beast, const int rounds) : first_player(std::move(c_player)), second_player(std::move(c_beast))
{
	
	this->rounds = std::make_shared<int>(std::move(rounds));
}

void game::isAttacking_first(std::unique_ptr<character> const& f_orderus, std::unique_ptr<character> const& f_beast)
{
	//1 orderus if first
	//0 beast is first

	if (first_player->get_speed() > second_player->get_speed())
		this->first = std::make_unique<int>(1);
	else
		if (first_player->get_speed() == second_player->get_speed())
			if (first_player->get_luck() >= second_player->get_luck())
				this->first = std::make_unique<int>(1);
			else this->first = std::make_unique<int>(0);

}

void game::switch_roles()
{
	std::unique_ptr<character> aux = std::move(first_player);
	first_player = std::move(second_player);
	second_player = std::move(aux);
}


void game::run()
{
	isAttacking_first(first_player, second_player);

	if (*first == 0) switch_roles();
	

	std::vector<int> iterations(*rounds);
	std::iota(begin(iterations), end(iterations), 0);

	for (auto iteration : iterations)
	{

		std::cout << "Iteration " << iteration << ":\n";

		bool _player_luck = second_player->is_lucky();

		if (!_player_luck)
		{
			if (first_player->rapidStrike()) {
				second_player->set_health(second_player->get_health() - (2 * first_player->get_strength() - second_player->get_defense()));
				//only orderus could hit with rapid strike or defend with magic shield
				std::cout << "Orderus hit with rapidStrike and the Beast has " << second_player->get_health() << " health left\n";	
			}
			else {

				if (second_player->magicShield()) {
					second_player->set_health(second_player->get_health() - (first_player->get_strength() - second_player->get_defense()) / 2);
					std::cout << "Beast hit but Orderus defends with Magic Shield and he has " << second_player->get_health() << " health left\n";

				}
				else
					second_player->set_health(second_player->get_health() - (first_player->get_strength() - second_player->get_defense()));

				if (*first == 1)
					std::cout << "Orderus hit and the beast has " << second_player->get_health() << " health left\n";
				else
					if (*first == 0)
						std::cout << "Beast hit and Orderus has " << second_player->get_health() << " health left\n";
			}
			
		}
		else 
			if(*first == 1)
				std::cout << "Beast get lucky, so Orderus miss his hit\n";
			else 
			if(*first == 0)
				std::cout << "Orderus get lucky, so Beast miss his hit\n";

		if (first_player->get_health() <= 0 || second_player->get_health() <= 0)
			gameover = false;

		if (*first == 1) *first = 0;
		else *first = 1;

		if (!gameover)
		{
			std::cout << "Game over\n";
			break;
		}

		switch_roles();

	}

}

