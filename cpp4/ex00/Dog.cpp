#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() {
    cout << "Dog constructor called" << endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    cout << "Dog copy constructor called" << endl;
}

Dog& Dog::operator=(const Dog& other) {
    cout << "Dog operator= called" << endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Dog::makeSound() const {
    cout << "Woof! Woof!" << endl;
}

Dog::~Dog() {
    cout << "Dog destructor called" << endl;
}


