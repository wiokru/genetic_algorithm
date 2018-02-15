#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "population.h"

class GeneticAlgorithm
{
    Population *base_population;
    Population *new_population;
public:
    GeneticAlgorithm(int size, string wanted);
    void geneticProcess(string wanted);
};

#endif // GENETICALGORITHM_H
