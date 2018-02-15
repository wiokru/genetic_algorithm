#include <iostream>
#include <cstdlib>
#include <time.h>
#include "population.h"
#include "dna.h"
#include "geneticalgorithm.h"

using namespace std;

int main()
{
    srand(time(NULL));

    string wanted;
    cout<<"Jakie slowo chcesz wylosowac? "<<endl;
    getline(cin,wanted);

    GeneticAlgorithm ga(200, wanted);
    ga.geneticProcess(wanted);

    return 0;
}
