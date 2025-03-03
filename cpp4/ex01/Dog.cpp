#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() {
    cout << "Dog constructor called" << endl;
    type = "Dog";
    brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other) {
    cout << "Dog copy constructor called" << endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    cout << "Dog operator= called" << endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Brain* Dog::getBrain() const {
    return brain;
}

void Dog::makeSound() const {
    cout << "Woof! Woof!" << endl;
}

Dog::~Dog() {
    cout << "Dog destructor called" << endl;
    delete brain;
}
