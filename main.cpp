#include "Animal.h"
#include <iostream>
#include <string>

int main(){
    Exhibit* exib = new Exhibit("Elephants", 100.0, 100.0);

    Elephant* ele1 = new Elephant("gandalf", MALE, BI, 50, 50);
    Elephant* ele2 = new Elephant("saruman", MALE, BI, 50, 50);

    exib->addAnimal(ele1);
    exib->addAnimal(ele2);
    ele1->waterFountain(exib, 10);
    std::cout<< std::to_string(ele1->wet) << "\n";
    std::cout<< std::to_string(ele2->wet) << "\n";
    std::cout<< ele1->confess(ele2);

    delete[] ele1, ele2;
}

