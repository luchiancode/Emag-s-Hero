#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <random>
#include <utility> 
#include <functional>
#include <memory>

#include "random_gen.h"

class character
{

protected:

	std::shared_ptr<int> _health = std::make_shared<int>();
	std::shared_ptr<int> _strength = std::make_shared<int>();
	std::shared_ptr<int> _defense = std::make_shared<int>();
	std::shared_ptr<int> _speed = std::make_shared<int>();
	std::shared_ptr<int> _luck = std::make_shared<int>();

	character() {};

	
public:
	std::shared_ptr<random_generator>random_stat = std::make_shared<random_generator>();

	void set_stats(const int&& health, const int&& strength, const int&& defense, const int&& speed, const int&& luck);

	int get_health() const;
	int get_strength() const;
	int get_defense() const;
	int get_speed() const;
	int get_luck() const;

	void set_health(const int&& new_health);
	void set_strength(const int&& new_strength);
	void set_defense(const int&& new_defense);
	void set_speed(const int&& new_speed);
	void set_luck (const int&& new_luck);

	bool is_lucky();

	character& operator=(character& other);

	virtual bool rapidStrike() const;
	virtual bool magicShield() const;

};

class player : public character
{
private:
	//stats ranges
	const std::pair<int, int> _healthRange = { 70, 100 };
	const std::pair<int, int> _strengthRange = { 70, 80 };
	const std::pair<int, int> _defenseRange = { 45, 55 };
	const std::pair<int, int> _speedRange = { 40, 50 };
	const std::pair<int, int> _luckRange = { 10, 30 };


public:
	player();

	//skills
	bool rapidStrike() const;
	bool magicShield() const;

	player& operator=(character& other);
};


class beast : public character
{
private:
	//stats ranges
	const std::pair<int, int> _healthRange = { 60, 90 };
	const std::pair<int, int> _strengthRange = { 60, 90 };
	const std::pair<int, int> _defenseRange = { 40, 60 };
	const std::pair<int, int> _speedRange = { 40, 60 };
	const std::pair<int, int> _luckRange = { 25, 40 };

public:
	beast();

	beast& operator=(character& other);
};



#endif