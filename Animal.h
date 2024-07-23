#ifndef __ANIMAL__
#define __ANIMAL__

#include <string>
#include <iostream>
#include "Space.h"
#include <random>

class Exhibit;

enum Gender{
    MALE, FEMALE, ZWITTER, NUM_GENDER
};
enum Sexuality{
    HETERO, HOMO, BI, ASEX, NUM_SEX
};
class Animal{
public:
    std::string name;
    Gender gender;
    Sexuality sex;
    int posX;
    int posY;
    bool wet = false;

    void move(int step, Exhibit* exib);
    virtual std::string show() = 0;
    virtual std::string confess(Animal* animal, Exhibit* exib) = 0;
    virtual std::string asciiModel() = 0;
    float distanceTo(Animal* animal);
    int randomNum(int x, int y);

    virtual ~Animal(){
    };
};

class Elephant : public Animal{
public:
    Elephant(std::string name, Gender gender, Sexuality sex, int posX=1, int posY=1){
        this->name = name;
        this->gender = gender;
        this->sex = sex;
        this->posX = posX;
        this->posY = posY;
    }
    ~Elephant() override {
        std::cout<< this->show() << " " << this->name << " has been killed :(" << std::endl;
    }
    
    std::string show() override;
    std::string confess(Animal* animal, Exhibit* exib) override;
    std::string asciiModel() override;
    
    std::string waterFountain(Exhibit* ex, float radius);
    
};

// class Icebear : public Animal{
// public:
//     Icebear(std::string name, Gender gender, Sexuality sex, int posX=1, int posY=1){
//         this->name = name;
//         this->gender = gender;
//         this->sex = sex;
//         this->posX = posX;
//         this->posY = posY;
//     }
//     ~Icebear() override{
//         std::cout<< this->show() << " " << this->name << " has been killed :(" << std::endl;
//     }

//     std::string show() override;
//     std::string confess(Animal* animal, Exhibit* exib) override;
//     std::string asciiModel() override;
// };

// class Hippo : public Animal{
// public:
//     Hippo(std::string name, Gender gender, Sexuality sex, int posX=1, int posY=1){
//         this->name = name;
//         this->gender = gender;
//         this->sex = sex;
//         this->posX = posX;
//         this->posY = posY;
//     }
//     ~Hippo() override{
//         std::cout<< this->show() << " " << this->name << " has been killed :(" << std::endl;
//     }

//     std::string show() override;
//     std::string confess(Animal* animal, Exhibit* exib) override;
//     std::string asciiModel() override;
// };

class Lion : public Animal{
public:
    Lion(std::string name, Gender gender, Sexuality sex, int posX=1, int posY=1){
        this->name = name;
        this->gender = gender;
        this->sex = sex;
        this->posX = posX;
        this->posY = posY;
    }
    ~Lion() override{
        std::cout<< this->show() << " " << this->name << " has been killed :(" << std::endl;
    }

    std::string show() override;
    std::string confess(Animal* animal, Exhibit* exib) override;
    std::string asciiModel() override;
};
#endif // __ANIMAL__