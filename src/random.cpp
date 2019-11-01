#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) : seed(s)
{
	if(seed == 0){
		std::random_device rd;
		seed = rd();
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper){
	for(size_t i(0) ; i < tab.size() ; ++i){
		tab[i] = uniform_double(lower, upper);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<> unif(lower, upper);
	return unif(rng);
}

void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd){
    for (size_t i(0) ; i < tab.size() ; ++i){
		tab[i] = normal(mean, sd);
	}
}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> norm(mean, sd);
	return  norm(rng);
}

void RandomNumbers::poisson(std::vector<int>& tab, double mean){
	for(size_t i(0) ; i < tab.size() ; ++i){
		tab[i] = poisson(mean);
	}
}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> pois(mean);
	return pois(rng);
}
