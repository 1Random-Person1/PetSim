//
// Created by admin on 9/15/2026.
//

#ifndef PETSIM_PETSIM_H
#define PETSIM_PETSIM_H
#include <string>
using namespace std;


class PetSim {

    public:

    PetSim();
    ~PetSim();

    PetSim(string name, int hungerLevel, int boredomLevel);

    void setName(string name);

    void setHungerLevel(int hungerLevel);

    void setBoredomLevel(int boredomLevel);

    string getName();

    int getHungerLevel();

    int getBoredomLevel();

    private:
    int hungerLevel;
    int boredomLevel;
    string name;

};


#endif //PETSIM_PETSIM_H
