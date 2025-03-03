#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() {
    cout << "Cat constructor called" << endl;
    type = "Cat";
    brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other) {
    cout << "Cat copy constructor called" << endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    cout << "Cat operator= called" << endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
    delete brain;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::makeSound() const {
    cout << "Meow!... *looks at you with disaproval*" << endl;
}
