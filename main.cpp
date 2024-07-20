#include "Animal.h"
#include <iostream>
#include <string>

int main(){
    Exhibit* exib = new Exhibit("Elephants", 10, 50);

    Elephant* ele1 = new Elephant("gandalf", MALE, BI, 5, 20);
    Elephant* ele2 = new Elephant("saruman", MALE, BI, 3, 30);

    exib->addAnimal(ele1);
    exib->addAnimal(ele2);
    exib->displayExhibit();

    delete[] ele1, ele2;
}

