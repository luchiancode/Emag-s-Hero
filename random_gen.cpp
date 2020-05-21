#include <iostream>
#include <random>
#include <functional>
#include <memory>

#include "random_gen.h"


void random_generator::set_limits(const int&& low, const int&& high) {
	*this->_low = low;
	*this->_high = high;
}

int random_generator::get_random_number() const
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(*_low, *_high);

	return distribution(generator);
}


