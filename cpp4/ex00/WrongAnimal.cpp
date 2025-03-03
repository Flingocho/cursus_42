#include "WrongAnimal.hpp"

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal() {
    cout << "WrongAnimal constructor called" << endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    cout << "WrongAnimal operator= called" << endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    cout << "Some strange WrongAnimal sound!" << endl;
}

WrongAnimal::~WrongAnimal() {
    cout << "WrongAnimal destructor called" << endl;
}
