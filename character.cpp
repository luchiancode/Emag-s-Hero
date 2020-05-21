#include <iostream>
#include <random>
#include <utility> 
#include <functional>
#include <memory>

#include "character.h"


void character::set_stats(const int&& health, const int&& strength, const int&& defense, const int&& speed, const int&& luck) {

	*this->_health = health;
	*this->_strength = strength;
	*this->_defense = defense;
	*this->_speed = speed;
	*this->_luck = luck;

}

int character::get_health() const { return *_health; }
int character::get_strength() const { return *_strength; }
int character::get_defense() const { return *_defense; }
int character::get_speed() const { return *_speed; }
int character::get_luck() const { return *_luck; }

bool character::is_lucky() {
	
	std::unique_ptr<random_generator>random_s = std::make_unique <random_generator>();
	random_s->getInstance();

	random_s->set_limits(1, 100);

	if (random_s->get_random_number() <= this->get_luck())
		return true;
	return false;

}

void character::set_health(const int&& new_health)
{
	*this->_health = new_health;
}

void character::set_strength(const int&& new_strength)
{	 
	*this->_strength = new_strength;
}	 
	 
void character::set_defense(const int&& new_defense)
{	 
	*this->_defense = new_defense;
}	 
	 
void character::set_speed(const int&& new_speed)
{	 
	*this->_speed = new_speed;
}	 
	 
void character::set_luck(const int&& new_luck)
{
	*this->_luck = new_luck;
}

bool character::rapidStrike() const { return false; }
bool character::magicShield() const { return false; }

character& character::operator=(character& other)
{
	if (this != &other) {
		this->set_health(std::move(other.get_health()));
		this->set_strength(std::move(other.get_strength()));
		this->set_defense(std::move(other.get_defense()));
		this->set_speed(std::move(other.get_speed()));
		this->set_luck(std::move(other.get_luck()));
	}
	return *this;
}

bool player::rapidStrike() const {
	std::unique_ptr<random_generator>random_s = std::make_unique <random_generator>();
	random_s->getInstance();

	random_s->set_limits(1, 10);

	if (random_s->get_random_number() == 1)
		return true;
	return false;
};

bool player::magicShield() const {
	std::unique_ptr<random_generator>random_m = std::make_unique <random_generator>();
	random_m->getInstance();

	random_m->set_limits(1, 10);

	if (random_m->get_random_number() <= 2)
		return true;
	return false;
};

player::player() {

	random_stat->getInstance();

	random_stat->set_limits(std::move(_healthRange.first), std::move(_healthRange.second));
	int rand_health = random_stat->get_random_number();

	random_stat->set_limits(std::move(_strengthRange.first), std::move(_strengthRange.second));
	int rand_strength = random_stat->get_random_number();

	random_stat->set_limits(std::move(_defenseRange.first), std::move(_defenseRange.second));
	int rand_defense = random_stat->get_random_number();

	random_stat->set_limits(std::move(_speedRange.first), std::move(_speedRange.second));
	int rand_speed = random_stat->get_random_number();

	random_stat->set_limits(std::move(_luckRange.first), std::move(_luckRange.second));
	int rand_luck = random_stat->get_random_number();


	set_stats(std::move(rand_health), std::move(rand_strength), std::move(rand_defense), std::move(rand_speed), std::move(rand_luck));
}

player& player::operator=(character& other)
{
	if (this != &other) {
		this->set_health(std::move(other.get_health()));
		this->set_strength(std::move(other.get_strength()));
		this->set_defense(std::move(other.get_defense()));
		this->set_speed(std::move(other.get_speed()));
		this->set_luck(std::move(other.get_luck()));
	}
	return *this;
}

beast::beast() {

	random_stat->getInstance();

	random_stat->set_limits(std::move(_healthRange.first), std::move(_healthRange.second));
	int rand_health = random_stat->get_random_number();

	random_stat->set_limits(std::move(_strengthRange.first), std::move(_strengthRange.second));
	int rand_strength = random_stat->get_random_number();

	random_stat->set_limits(std::move(_defenseRange.first), std::move(_defenseRange.second));
	int rand_defense = random_stat->get_random_number();

	random_stat->set_limits(std::move(_speedRange.first), std::move(_speedRange.second));
	int rand_speed = random_stat->get_random_number();

	random_stat->set_limits(std::move(_luckRange.first), std::move(_luckRange.second));
	int rand_luck = random_stat->get_random_number();


	set_stats(std::move(rand_health), std::move(rand_strength), std::move(rand_defense), std::move(rand_speed), std::move(rand_luck));
}

beast& beast::operator=(character& other)
{
	if (this != &other) {
		this->set_health(std::move(other.get_health()));
		this->set_strength(std::move(other.get_strength()));
		this->set_defense(std::move(other.get_defense()));
		this->set_speed(std::move(other.get_speed()));
		this->set_luck(std::move(other.get_luck()));
	}
	return *this;
}