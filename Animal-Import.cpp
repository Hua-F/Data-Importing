#include "Animal.h"
#include <fstream>
#include <string>

using namespace std;

Animal::Animal(string s, bool f){
    name = "Unknown Name ";
    hasFur = f;
    numLegs = 4;
    species = s;
}

Animal::Animal(string n, string s, bool f, int legs){
    name = n;
    hasFur = f;
    numLegs = legs;
    species = s;
}

string Animal::getName() const{
	return name;
}

void Animal::setName(string name) {
	this->name = name;
}

string Animal::getSpecies() const {
	return species;
}

int Animal::getNumLegs() const{
	return numLegs;
}

void Animal::setNumLegs(int num){
	numLegs = num;
}

bool Animal::getHasFur() const{
	return hasFur;
}

void Animal::move(){
	cout << "\n" << name << " moves like a " << species << "\n";
}

void Animal::makeSound(){
	cout << "\n" << name << " makes a " << species << " sound \n";
}

void Animal::print(){
	cout << "\nAnimal { ";
	cout << "name = " << name << ",\n";
	cout << "species = " << species << ",\n";
	cout << "numLegs = " << numLegs << ",\n";
	if(hasFur)
		cout << "hasFur = true }\n";
	else
		cout << "hasFur = false }\n";
}

bool Animal::operator==(const Animal& anotherAnimal) const {
    if (this->species == anotherAnimal.species && this->hasFur == anotherAnimal.hasFur && this->name == anotherAnimal.name)
	{ 
		return true;
	}
	return false;
}

string trim(const string &input) {
    string whiteSpaceChars = " \n\t";
    int start = input.find_first_not_of(whiteSpaceChars);
    int end = input.find_last_not_of(whiteSpaceChars);
    int length = end - start + 1;
    return input.substr(start, length);
}

int main() {
    
    ifstream inFile;
    inFile.open("AnimalData.csv");

    Animal* animals[50];
    int numAnimals = 0;
    
    string name, species, hasFurStr;
    bool hasFur;
    int numLegs;

    while (getline(inFile, name, ',') && getline(inFile, species, ',') && getline(inFile, hasFurStr, ',')) {
        inFile >> numLegs;
        
        name = trim(name);
        species = trim(species);
        hasFurStr = trim(hasFurStr);

        Animal newAnimal(name, species, hasFur, numLegs);

        bool isDuplicate = false;
        for (int i = 0; i < numAnimals; i++) {
            if (newAnimal == *animals[i]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            animals[numAnimals] = new Animal(newAnimal);
            numAnimals++;
        }

        inFile.ignore();
    }

    inFile.close();

    for (int i = 0; i < numAnimals; i++) {
        if (i % 2 == 0) {
            animals[i]->makeSound();
        } else {
            animals[i]->move();
        }
        animals[i]->print();
    }

    return 0;
}
