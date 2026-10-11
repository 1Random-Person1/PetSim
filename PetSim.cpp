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

void PetSim::setName(string name) {
    this->name = name;
}

string PetSim::getName() {
    return name;
}

void PetSim::setHungerLevel(int hungerLevel) {

    this->hungerLevel = hungerLevel;

    if (this->hungerLevel > 100) {
        this->hungerLevel = 100;
    } else if (this->hungerLevel < 0) {
        this->hungerLevel = 0;
    }
}

int PetSim::getHungerLevel() {
    return hungerLevel;
}

void PetSim::setBoredomLevel(int boredomLevel) {

    this->boredomLevel = boredomLevel;

    if (this->boredomLevel > 100) {
        this->boredomLevel = 100;
    } else if (this->boredomLevel < 0) {
        this->boredomLevel = 0;
    }
}

int PetSim::getBoredomLevel() {
    return boredomLevel;
}

int PetSim::petMood() {

    return getHungerLevel() + getBoredomLevel();

}

void PetSim::talk() {

    int mood = petMood();

    if (mood < 7) {
        cout << getName() << " is feeling happy." << endl;
    } else if (mood >= 7 and mood < 16) {
        cout << getName() << " is feeling okay." << endl;
    } else if (mood >= 16 and mood <= 21) {
        cout << getName() << " is feeling frustrated." << endl;
    } else if (mood > 21) {
        cout << getName() << " is feeling mad" << endl;
    }

    passTime();

    displayPetBehavior();

}

void PetSim::feedPet(int foodAmount) {

    if (hungerLevel <= 0) {
        foodAmount = 0;
        cout << getName() << " is not hungry." << endl;
    } else {
        setHungerLevel(hungerLevel - foodAmount);
        cout << getName() << " has been fed." << endl;
    }

    passTime();

    displayPetBehavior();

}

void PetSim::play(int playAmount) {

    if (boredomLevel <= 0) {
        playAmount = 0;
        cout << getName() << " is not bored." << endl;
    } else {
        setBoredomLevel(boredomLevel - playAmount);
        cout << getName() << " has been played with." << endl;
    }

    passTime();

    displayPetBehavior();


}

void PetSim::passTime(int time) {

    setHungerLevel(hungerLevel + time);
    setBoredomLevel(boredomLevel + time);

}

void PetSim::displayPetBehavior() {

    cout << "Hunger Level: " << getHungerLevel() << endl;

    cout << "Boredom Level: " << getBoredomLevel() << endl;

    if (getHungerLevel() && getBoredomLevel() < 3) {
        cout << getName() << " is not hungry or bored." << endl;
    }

    if (getBoredomLevel() > 3 && getBoredomLevel() < 11) {
        cout << getName() << " is a little bored." << endl;
    } else if (getBoredomLevel() >= 11) {
        cout << getName() << " is very bored." << endl;
    }

    if (getHungerLevel() > 3 && getHungerLevel() < 11) {
        cout << getName() << " is a little hungry." << endl;
    } else if (getHungerLevel() >= 11) {
        cout << getName() << " is very hungry." << endl;
    }

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

                feedPet();
                break;

            case 3:

                play();
                break;

            case 4:

                run = false;

            default:

                break;
        }
    }
}