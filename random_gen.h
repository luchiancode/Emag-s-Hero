#ifndef _RANDOM_GEN_H
#define _RANDOM_GEN_H

class random_generator
{

private:
	std::unique_ptr<int> _low = std::make_unique<int>();
	std::unique_ptr<int> _high = std::make_unique<int>();

	
public:
	random_generator() {}


	static std::shared_ptr<random_generator> getInstance() {
		static std::shared_ptr<random_generator> theInstance = std::make_shared<random_generator>();
		return theInstance;
	}

	void set_limits(const int&& low, const int&& high);

	int get_random_number() const;
};


#endif
