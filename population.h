#ifndef POPULATION_H
#define POPULATION_H

#include "dna.h"


class Population
{
    vector<DNA*> population;
    vector<DNA*> possible_parents;
    int size;
    DNA* parent1;
    DNA* parent2;
    int population_count; //numer populacji, kolejnosc jakby
    string wanted;
public:
    Population(int size, string wanted);
    Population(int size, int population_count, string wanted);
    void selectParents();
    void normalize();
    void createPossibleParents();
    DNA* makeChild();
    int getPopulation_count() const;
    void setPopulation_count(int value);
    int getSize() const;
    vector<DNA *> getPopulation() const;
    void addChild(DNA * ch);
    Population & operator = (const Population &old);

};

#endif // POPULATION_H
