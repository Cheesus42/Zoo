#include "Animal.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

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
int randomNum(int x, int y);
std::string generateRandomString(int length);
Gender getRandomGender();
Sexuality getRandomSex();
int main(){
    using namespace std::this_thread;
    using namespace std::chrono;

    Exhibit* exib = new Exhibit("Leons Folterkammer", 50, 10);

    for (int i = 0; i < 5; ++i)
    {
        exib->addAnimal(new Elephant(generateRandomString(randomNum(3, 7)), getRandomGender(), getRandomSex(), randomNum(1, 49), randomNum(1, 9)));
    }
    
    for (int i = 0; i < 1000; ++i)
    {
        sleep_for(milliseconds(500));
        std::system("cls");
        exib->run();
    }



}

int randomNum(int x, int y){
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(x, y);
    return distrib(gen);
}
std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz"
                                   "0123456789";
    std::random_device rd; // Zufallszahlengenerator für die Initialisierung
    std::mt19937 generator(rd()); // Mersenne-Twister Zufallszahlengenerator
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += characters[distribution(generator)];
    }

    return randomString;
}
Gender getRandomGender() {
    // Zufallszahlengenerator initialisieren
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, NUM_GENDER - 1);

    // Zufälligen Index erzeugen
    int randomIndex = distribution(generator);

    // Zufälliges Element zurückgeben
    return static_cast<Gender>(randomIndex);
}
Sexuality getRandomSex() {
    // Zufallszahlengenerator initialisieren
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, NUM_SEX - 1);

    // Zufälligen Index erzeugen
    int randomIndex = distribution(generator);

    // Zufälliges Element zurückgeben
    return static_cast<Sexuality>(randomIndex);
}