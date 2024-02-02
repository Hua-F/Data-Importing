#ifndef H_Animal_250_F22
#define H_Animal_250_F22
#include <iostream>

using namespace std;

class Animal {
public:
    Animal(string, bool);
    Animal(string, string, bool, int);
    string getName() const;
    void setName(string);
    string getSpecies() const;
    int getNumLegs() const;
    void setNumLegs(int);
    bool getHasFur() const;
    virtual void move();
    virtual void makeSound();
    virtual void print();
    bool operator==(const Animal& anotherAnimal) const;
private:
    int numLegs;
    bool hasFur;
    string name;
    string species;
};

#endif

class Bird : public Animal {
public:
    Bird(string, bool, bool, int);
    Bird(string, string, bool, int, bool, int);
    double getWingspan() const;
    void setWingspan(double);
    int getAge() const;
    void setAge(int);
    bool getNocturnal() const;
    void setNocturnal(bool);
    void makeSound() override;
    void move() override;
    void print() override;
private:
    double wingspan;
    int age;
    bool nocturnal;
};
