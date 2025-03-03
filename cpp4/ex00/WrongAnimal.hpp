#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class WrongAnimal {
    protected:
        string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();

        void makeSound() const;
};
