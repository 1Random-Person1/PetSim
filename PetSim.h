/*PetSim class that declares the functions that will be used for the project */

#ifndef PETSIM_PETSIM_H
#define PETSIM_PETSIM_H
#include <string>
#include <iostream>

using namespace std;


class PetSim {

    public:

    PetSim(int hungerLevel, int boredomLevel, string name);

    void setName(string name);

    string getName();

    void setHungerLevel(int hungerLevel);

    int getHungerLevel();

    void setBoredomLevel(int boredomLevel);

    int getBoredomLevel();

    void talk();

    void feedPet(int foodAmount = 3);

    void play(int playAmount = 3);

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
