#include "geneticalgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int size, string wanted){
    base_population = new Population(size, wanted);
    new_population = new Population(size, base_population->getPopulation_count()+1, wanted);
}
void GeneticAlgorithm::geneticProcess(string wanted){
    bool _continue_ = true;
    while (new_population->getPopulation().size() < base_population->getSize() && _continue_){
        base_population->selectParents();
        DNA *child = base_population->makeChild();
        //cout<<child->getGenotyp()<<" "<<child->getFitness_rate()<<endl;
        new_population->addChild(child);

        if (child->getGenotyp() == wanted){
            cout << "WYLOSOWANO: " << child->getGenotyp()<<endl;
            cout << "NUMER POPULACJI: " << new_population->getPopulation_count()<<endl;
            _continue_=false;
        }
        if (_continue_ == false) break;
    }

    if(_continue_){
        int s = base_population->getSize();
        int population_count = new_population->getPopulation_count();
        base_population->operator = (*new_population);
        delete new_population;
        new_population = new Population (s, population_count+1, wanted);
        geneticProcess(wanted);
    }
    return;
}
