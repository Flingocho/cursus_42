#include "WrongCat.hpp"

using std::cout;
using std::endl;

WrongCat::WrongCat() {
    cout << "WrongCat constructor called" << endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    cout << "WrongCat copy constructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    cout << "WrongCat operator= called" << endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const {
    cout << "Wrongmeooooow!" << endl;
}

WrongCat::~WrongCat() {
    cout << "WrongCat destructor called" << endl;
}
