#include "dna.h"

//konstruktor losujacy wartosc
DNA::DNA(int length, string wanted){
    string alphabet = "ABCDEFGHIJKLMNOPRSTUWXYZabcdefghijklmnoprstuwxyz. ";
    string temp="";
    for (int i=0; i<length; i++){
        int index=rand()%alphabet.length();
        temp+=(alphabet[index]);
    }
    setGenotyp(temp,wanted);
    this->length = genotyp.length();
    //this->fitness_rate = fitness(wanted);
}

//konstruktor ustawiajacy wartosc
DNA::DNA(string name, string wanted){
    this->genotyp = name;
    this->length = genotyp.length();
    this->fitness_rate = fitness(wanted);
}

//konstruktor kopiujacy
DNA::DNA (const DNA &o2){
    this->genotyp = o2.genotyp;
    this->fitness_rate = o2.fitness_rate;
    this->fit_rate_normalization = o2.fit_rate_normalization;
    this->length = o2.length;
}

//genotyp - getter i setter
string DNA::getGenotyp() const{
    return genotyp;
}

void DNA::setGenotyp(const string &value, string wanted){
    genotyp = value;
    fitness_rate = fitness(wanted);
}

//fittnes rate - getter
int DNA::getFitness_rate() const{
    return fitness_rate;
}

//funkcje
int DNA::fitness(string wanted){
    int p=0;
    for (unsigned int i=0; i<wanted.length(); i++){
        if (genotyp[i] == wanted[i])
            p++;
    }
    return pow(2, p);
}

string DNA::crossover( DNA o2){
    string after_crossover;
    unsigned int middle =(unsigned int)ceil(genotyp.length()/2);
    unsigned int i=0;
    while (i<genotyp.length()){
        if(i<middle)
            after_crossover+=genotyp[i];
        else
            after_crossover+=o2.getGenotyp()[i];
        i++;
    }
    return after_crossover;
}

void DNA::mutate(){
    int check = rand()%100;
    if (check % 13==0){ //jesli wylosuje wielokrotnosc 13, to nastapi mutacja
        //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        string alphabet = "ABCDEFGHIJKLMNOPRSTUWXYZabcdefghijklmnoprstuwxyz. ";
        int index_to_change = rand()%genotyp.length();
        int new_letter_index = rand()%alphabet.length();

        genotyp[index_to_change] = alphabet[new_letter_index];
    }
}

double DNA::getFit_rate_normalization() const{
    return fit_rate_normalization;
}

void DNA::setFit_rate_normalization(double value){
    fit_rate_normalization = value;
}
