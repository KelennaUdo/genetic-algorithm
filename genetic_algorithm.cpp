// C++ program to create target string, starting from 
// random string using Genetic Algorithm 

#include <iostream> 
#include <string>
#include<vector>
#include<algorithm>
#include<time.h>
#include "Individual.h"
using namespace std; 

// Number of individuals in each generation 
#define POPULATION_SIZE 100 

 

// Valid Genes 
const string GENES = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}"; 

// Target string to be generated 
string TARGET {}; 

// Function to generate random numbers in given range 
int random_num(int start, int end) 
{ 
	int range = (end-start)+1; 
	int random_int = start+(rand()%range); 
	return random_int; 
} 

// Create random genes for mutation 
char mutated_genes() 
{ 
	int len = GENES.size(); 
	int r = random_num(0, len-1); 
	return GENES[r]; 
} 

// create chromosome or string of genes 
string create_gnome() 
{ 
	int len = TARGET.size(); 
	string gnome = ""; 
	for(int i = 0;i<len;i++) 
		gnome += mutated_genes(); 
	return gnome; 
} 

// Perform mating and produce new offspring 
Individual mate(const Individual &par1, const Individual &par2) 
{ 
	// chromosome for offspring 
	string child_chromosome = ""; 

	int len = par1.chromosome.size(); 
	for(int i = 0;i<len;i++) 
	{ 
		// random probability 
		float p = random_num(0, 100)/100; 

		// if prob is less than 0.45, insert gene 
		// from parent 1 
		if(p < 0.45) 
			child_chromosome += par1.chromosome[i]; 

		// if prob is between 0.45 and 0.90, insert 
		// gene from parent 2 
		else if(p < 0.90) 
			child_chromosome += par2.chromosome[i]; 

		// otherwise insert random gene(mutate), 
		// for maintaining diversity 
		else
			child_chromosome += mutated_genes(); 
	} 

	// create new Individual(offspring) using 
	// generated chromosome for offspring 
	return Individual(child_chromosome); 
} 


// Calculate fitness score, it is the number of 
// characters in string which differ from target 
// string. 
void cal_fitness(Individual &Individual, const string &TARGET) 
{ 
	int len = TARGET.size(); 
	int fitness = 0; 
	for(int i = 0;i<len;i++) 
	{ 
		if(Individual.chromosome[i] != TARGET[i]) 
			fitness++; 
	} 
	Individual.fitness = fitness;

}; 



// Driver code 
int main() 
{ 
	std::cout 	<< "Welcome to my genetic algorithm program!\n" 
				<<"A Genetic Algorithm (GA) is an optimization technique inspired by the process of natural selection.\n"
				<<"It mimics biological evolution to solve complex problems by iteratively improving a population of candidate solutions.\n"
				<< "This Algorithm will take in a target string and use a natural selection process to generate the target string from\n"
				<< "a starting generation of candidates with randomly generated strings.\n"
				<< "The closest sting in each generation will be displayed as the program runs.\n"
				<< "Please Enter a target string: ";
	
	getline(std::cin, TARGET);
	srand((unsigned)(time(0))); 

	// current generation 
	int generation = 0; 

	vector<Individual> population; 
	bool found = false; 

	// create initial population 
	for(int i = 0;i<POPULATION_SIZE;i++) 
	{ 
		string gnome = create_gnome(); 
		Individual person{gnome};
		cal_fitness(person, TARGET);
		population.push_back(person); 
	} 

	while(! found) 
	{ 
		// sort the population in increasing order of fitness score 
		sort(population.begin(), population.end()); 

		// if the individual having lowest fitness score ie. 
		// 0 then we know that we have reached to the target 
		// and break the loop 
		if(population[0].fitness <= 0) 
		{ 
			found = true; 
			break; 
		} 

		// Otherwise generate new offsprings for new generation 
		vector<Individual> new_generation; 

		// Perform Elitism, that mean 10% of fittest population 
		// goes to the next generation 
		int s = (10*POPULATION_SIZE)/100; 
		for(int i = 0;i<s;i++)
		{
			new_generation.push_back(population[i]); 
		}

		// From 50% of fittest population, Individuals 
		// will mate to produce offspring 
		s = (90*POPULATION_SIZE)/100; 
		for(int i = 0;i<s;i++) 
		{ 
			int len = population.size(); 
			int r = random_num(0, len/2); 
			Individual parent1 = population[r]; 
			r = random_num(0, len/2); 
			Individual parent2 = population[r]; 
			Individual offspring = mate(parent1, parent2); 
			cal_fitness(offspring, TARGET);
			new_generation.push_back(offspring); 
		} 
		population = new_generation; 
		std::cout<< "Generation: " << generation << "\t"; 
		std::cout<< "String: "<< population[0].chromosome <<"\t"; 
		std::cout<< "Fitness: "<< population[0].fitness << "\n"; 

		generation++; 
	} 
	std::cout<< "Generation: " << generation << "\t"; 
	std::cout<< "String: "<< population[0].chromosome <<"\t"; 
	std::cout<< "Fitness: "<< population[0].fitness << "\n"; 
} 
