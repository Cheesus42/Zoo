#include "Animal.h"
#include <iostream>
#include <string>
#include <cstdlib>

std::istream& operator>>(std::istream& stream, Gender& gender){
    std::string input;
    stream >> input;
    if(input == "Male"){
        gender = Gender::MALE;
    }else if(input == "Female"){
        gender = Gender::FEMALE;
    }else if(input == "Zwitter"){
        gender = Gender::ZWITTER;
    }else{
        stream.setstate(std::ios::failbit);
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, Sexuality& sex){
    std::string input;
    stream >> input;
    if(input == "Hetero"){
        sex = Sexuality::HETERO;
    }else if(input == "Homo"){
        sex = Sexuality::HOMO;
    }else if(input == "Bi"){
        sex = Sexuality::BI;
    }else{
        stream.setstate(std::ios::failbit);
    }
    return stream;
}

int main(){
    Exhibit* exib = new Exhibit("Elephants", 50, 10);

    Elephant* ele1 = new Elephant("gandalf", MALE, BI, 20, 5);
    Elephant* ele2 = new Elephant("saruman", MALE, BI, 30, 3);

    exib->addAnimal(ele1);
    exib->addAnimal(ele2);
    exib->displayExhibit();

    std::cout<< ele1->confess(ele2);
    //delete ele1;
    // for (int i = 0 - 1; i < 1000; i++)
    // {
    //     std::system("cls");
    //     ele1->move(1, exib);
    //     std::cout<< std::endl;
    //     exib->displayExhibit();
    // }

    // std::string s;
    // std::cout<< "add to add a new Animal";
    // std::cin>> s;
    // if(s == "add"){
    //     std::cout<< "what kind of animal: ";
    //     std::cin>> s;
    //     std::cout<< std::endl;
    //     if(s == "elephant"){
    //         std::string name;
    //         Gender gender;
    //         Sexuality sex;
    //         std::cout<< "Give a Name for your Elephant: ";
    //         std::cin >> name;
    //         std::cout<< std::endl;
    //         std::cout<< "What's their Gender: ";
    //         std::cin >> gender;
    //         std::cout<< std::endl;
    //         std::cout<< "What's their sexual orientation: ";
    //         std::cin >> sex;
    //         std::cout<< std::endl;
    //         Elephant* customEl = new Elephant(name, gender, sex, 10, 10);
    //         exib->addAnimal(customEl);
    //         exib->displayExhibit();
    //     }
    // }
}

