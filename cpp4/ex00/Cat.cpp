#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() : Animal("Cat"){
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    cout << "Cat copy constructor called" << endl;
}

Cat& Cat::operator=(const Cat& other) {
    cout << "Cat operator= called" << endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

void Cat::makeSound() const {
    cout << "Meooooow!" << endl;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
}
