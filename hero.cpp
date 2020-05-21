#include <iostream>
#include <random>
#include <utility> 
#include <functional>
#include <memory>

#include "game.h"
#include "character.h"


int main()
{
	
	std::unique_ptr<character> _orderus = std::make_unique<player>();
	std::unique_ptr<character> _beast   = std::make_unique<beast>();
		 
	const int i = 20;

	std::unique_ptr<game> emag = std::make_unique<game>(_orderus,_beast, i );

	emag->run();

	
	system("pause");
}