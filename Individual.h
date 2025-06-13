#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#pragma once

class Individual
{
    friend void cal_fitness(Individual &Individual, const std::string &TARGET); 
    friend Individual mate(const Individual &par1,const Individual &par2);
public:
    Individual();
    std::string chromosome{}; 
	int fitness{}; 

	Individual(std::string chromosome): chromosome(chromosome){};
	Individual mate(Individual parent2); 	
    bool operator<(const Individual &ind2){ 
	return this->fitness < ind2.fitness; 
};
    ~Individual()= default;

private:

};

#endif