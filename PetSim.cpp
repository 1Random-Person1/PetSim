//
// Created by admin on 9/15/2026.
//

#include "PetSim.h"

PetSim::PetSim(int hungerLevel, int boredomLevel, string name) {

    cout << "Welcome to PetSim! A program that allows you to care for a virtual pet" << endl;
    cout << "Please provide a name for your pet:" << endl;
    cin >> name;

    setName(name);
    setHungerLevel(hungerLevel);
    setBoredomLevel(boredomLevel);
}

int maxVal = 100;
int lowVal = 0;

void PetSim::setName(string name) {
    this->name = name;
}

string PetSim::getName() {
    return name;
}

void PetSim::setHungerLevel(int hungerLevel) {
    this->hungerLevel = hungerLevel;
}

int PetSim::getHungerLevel() {
    return hungerLevel;
}

void PetSim::setBoredomLevel(int boredomLevel) {
    this->boredomLevel = boredomLevel;
}

int PetSim::getBoredomLevel() {
    return boredomLevel;
}

int PetSim::petMood() {

    return getHungerLevel() + getBoredomLevel();

}

void PetSim::talk() {

    int mood = petMood();

    if (mood < 7 && mood <= lowVal) {
        cout << getName() << " is feeling happy." << endl;
    } else if (mood >= 7 and mood < 16) {
        cout << getName() << " is feeling okay." << endl;
    } else if (mood >= 16 and mood <= 21) {
        cout << getName() << " is feeling frustrated." << endl;
    } else if (mood > 21 and mood <= maxVal) {
        cout << getName() << " is feeling mad" << endl;
    }
    passTime();

}

void PetSim::feedPet(int foodAmount) {

}

void PetSim::play(int playAmount) {

}

void PetSim::passTime(int time) {

    time += 1;

}

void PetSim::displayPetBehavior() {

    string name = getName();
    int hunger = getHungerLevel();
    int boredom = getBoredomLevel();

    cout << "Pet Info:" << endl;
    cout << "Name: " << name << endl;
    cout << "Hunger Level: " << hunger << endl;
    cout << "Boredom Level: " << boredom << endl;
}

void PetSim::menu() {

    int choice;
    bool run = true;

    while (run != false) {

        cout << "Please select an option: 1 - Talk | 2 - Feed | 3- Play | 4 - Exit" << endl;

        cin >> choice;

        switch (choice) {

            case 1:

                talk();

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                run = false;

            default:

                break;
        }
    }
}