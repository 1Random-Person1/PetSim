//
// Created by admin on 9/15/2026.
//

#ifndef PETSIM_PETSIM_H
#define PETSIM_PETSIM_H
#include <string>
#include <iostream>
#include <limits>
using namespace std;


class PetSim {

    public:

    PetSim(int hungerLevel, int boredomLevel, string name);

    PetSim();

    void setName(string name);

    string getName();

    void setHungerLevel(int hungerLevel);

    int getHungerLevel();

    void setBoredomLevel(int boredomLevel);

    int getBoredomLevel();

    void talk();

    void feedPet(int foodAmount = 4);

    void play(int playAmount = 4);

    void displayPetBehavior();

    void menu();

    private:
    int hungerLevel;
    int boredomLevel;
    string name;

    int petMood();
    void passTime(int time = 1);

};


#endif //PETSIM_PETSIM_H
