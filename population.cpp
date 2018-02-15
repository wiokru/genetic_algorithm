#include "population.h"

Population::Population(int size, string wanted){
    this->size = size;
    this->population_count = 0;
    this->wanted = wanted;
    for (int i=0; i<size; i++){
        DNA *temp = new DNA(wanted.length(), wanted);
        temp->fitness(wanted);
        population.push_back(temp);
    }
    normalize();
    //for(int i=0; i<size; i++) cout<<population[i]->getFit_rate_normalization()<<endl;
    createPossibleParents();
    //cout<<possible_parents.size()<<endl;
}

Population::Population(int size, int population_count, string wanted){
    this->size = size;
    this->population_count = population_count;
    this->wanted = wanted;
}
void Population::selectParents(){
    //cout<<possible_parents.size()<<endl;
    int par1 = rand()%possible_parents.size();
    int par2 = rand()%possible_parents.size();

    parent1 = possible_parents[par1];
    parent2 = possible_parents[par2];
}

void Population::normalize(){
    unsigned int min=0, max=0; //indeksy dla min i max fitness_rate

   // double val;

    for (unsigned int i=1; i<population.size(); i++){
        if(population[i]->getFitness_rate() < population[min]->getFitness_rate())
            min=i;
        else if (population[i]->getFitness_rate() > population[max]->getFitness_rate())
            max=i;
    }

    for (int i=0; i<size; i++){
        double a = population[i]->getFitness_rate() - population[min]->getFitness_rate();
        double b = population[max]->getFitness_rate() - population[min]->getFitness_rate();
        double val = a/(double)b;
        population[i]->setFit_rate_normalization(val);
    }

}
void Population::createPossibleParents(){
    for (int i=0; i<size; i++){
        for (int j=0; j<(population[i]->getFit_rate_normalization())*100; j++){
            possible_parents.push_back(population[i]);
        }
    }
}

DNA* Population::makeChild(){
    string ch = parent1->crossover(*parent2);
    DNA* child = new DNA(ch, this->wanted);
    child->mutate();
    return child;
}

int Population::getPopulation_count() const{
    return population_count;
}

void Population::setPopulation_count(int value){
    population_count = value;
}

int Population::getSize() const{
    return size;
}
vector<DNA *> Population::getPopulation() const{
    return population;
}
void Population::addChild(DNA *ch){
    population.push_back(ch);
}

Population & Population::operator = (const Population &old){
    this->size = old.size;
    this->population.clear();
    this->possible_parents.clear();
    this->population = old.population;
    this->normalize();
    this->createPossibleParents();
//    cout<<this->possible_parents.size()<<endl;
    return *this;
}
