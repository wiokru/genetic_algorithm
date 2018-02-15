#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class DNA
{
    string genotyp;
    int fitness_rate;
    double fit_rate_normalization;
    int length;

public:
    DNA(int length, string wanted);
    DNA(string name, string wanted);
    DNA(const DNA &o2);

    string getGenotyp() const;
    void setGenotyp(const string &value, string wanted);
    int getFitness_rate() const;

    int fitness(string wanted);
    string crossover(DNA o2);
    void mutate();
    double getFit_rate_normalization() const;
    void setFit_rate_normalization(double value);
};

#endif // DNA_H
