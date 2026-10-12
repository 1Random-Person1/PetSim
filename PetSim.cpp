/*Main file that implements the PetSim class with its constructor, fuctions for actions, and gameplay loop display*/

#include "PetSim.h"

//Constructor and gets the pets name from user
PetSim::PetSim(int hungerLevel, int boredomLevel, string name) {

    cout << "Welcome to PetSim! A program that allows you to care for a virtual pet" << endl;
    cout << "Please provide a name for your pet:" << endl;
    cin >> name;

    setName(name);
    setHungerLevel(hungerLevel);
    setBoredomLevel(boredomLevel);
}

//Sets the name
void PetSim::setName(string name) {
    this->name = name;
}

//Returns the name
string PetSim::getName() {
    return name;
}

//Sets the hunger level and provides a check for the 0-100 limit
void PetSim::setHungerLevel(int hungerLevel) {

    this->hungerLevel = hungerLevel;

    if (this->hungerLevel > 100) {
        this->hungerLevel = 100;
    } else if (this->hungerLevel < 0) {
        this->hungerLevel = 0;
    }
}

//Returns the hunger level
int PetSim::getHungerLevel() {
    return hungerLevel;
}

//Sets the boredom level and provides a check for the 0-100 limit
void PetSim::setBoredomLevel(int boredomLevel) {

    this->boredomLevel = boredomLevel;

    if (this->boredomLevel > 100) {
        this->boredomLevel = 100;
    } else if (this->boredomLevel < 0) {
        this->boredomLevel = 0;
    }
}

//Returns the boredom level
int PetSim::getBoredomLevel() {
    return boredomLevel;
}

//Returns the sum of the hunger and boredom level
int PetSim::petMood() {

    return getHungerLevel() + getBoredomLevel();

}

//Prints the specific line of info based on the mood level
void PetSim::talk() {

    int mood = petMood();

    if (mood < 7) {
        cout << getName() << " is feeling happy." << endl;
    } else if (mood >= 7 && mood < 16) {
        cout << getName() << " is feeling okay." << endl;
    } else if (mood >= 16 && mood <= 21) {
        cout << getName() << " is feeling frustrated." << endl;
    } else {
        cout << getName() << " is feeling mad" << endl;
    }

    displayPetBehavior();

    passTime();

}

//Allows the user to feed the pet
void PetSim::feedPet(int foodAmount) {

    if (foodAmount > 4) {
        foodAmount = 4;
    } else if (foodAmount < 0) {
        foodAmount = 0;
    }

    if (getHungerLevel() <= 0) {
        cout << getName() << " is not hungry." << endl;
    } else {
        setHungerLevel(getHungerLevel() - foodAmount);
        cout << getName() << " has been fed." << endl;
    }

    displayPetBehavior();

    passTime();

}

//Allows the user to play with the pet
void PetSim::play(int playAmount) {

    if (playAmount > 4) {
        playAmount = 4;
    } else if (playAmount < 0) {
        playAmount = 0;
    }

    if (getBoredomLevel() <= 0) {
        cout << getName() << " is not bored." << endl;
    } else {
        setBoredomLevel(getBoredomLevel() - playAmount);
        cout << getName() << " has been played with." << endl;
    }

    displayPetBehavior();

    passTime();

}

//Increases hunger and boredom level as time passes
void PetSim::passTime(int time) {

    setHungerLevel(getHungerLevel() + time);
    setBoredomLevel(getBoredomLevel() + time);

}

//Prints the specific hunger and boredom level, then prints the specific line of info
//based on the value of hunger and boredom

void PetSim::displayPetBehavior() {

    cout << "Hunger Level: " << getHungerLevel() << endl;

    cout << "Boredom Level: " << getBoredomLevel() << endl;

    if (getHungerLevel() < 3) {
        cout << getName() << " is not hungry." << endl;
    }
    if (getHungerLevel() >= 3 && getHungerLevel() <= 11) {
        cout << getName() << " is a little hungry." << endl;
    } else if (getHungerLevel() > 11) {
        cout << getName() << " is very hungry." << endl;
    }

    if (getBoredomLevel() < 3) {
        cout << getName() << " is not bored." << endl;
    }
    if (getBoredomLevel() >= 3 && getBoredomLevel() <= 11) {
        cout << getName() << " is a little bored." << endl;
    } else if (getBoredomLevel() > 11) {
        cout << getName() << " is very bored." << endl;
    }

}

//Prints a menu for the user, allowing them to select a specific case
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
                break;

            default:

                break;
        }
    }
}