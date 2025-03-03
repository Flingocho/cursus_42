#include "ICharacter.hpp"
#include <iostream>

using std::cout;
using std::endl;

ICharacter::ICharacter() {
    cout << "ICharacter default constructor called" << endl;
}

ICharacter::ICharacter(const ICharacter& other) {
    (void)other;
    cout << "ICharacter copy constructor called" << endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    (void)other;
    cout << "ICharacter assignment operator called" << endl;
    return *this;
}

ICharacter::~ICharacter() {
    cout << "ICharacter destructor called" << endl;
}
