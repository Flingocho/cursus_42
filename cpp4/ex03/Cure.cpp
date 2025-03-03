#include "Cure.hpp"
#include <iostream>

using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure") {
    cout << "Cure constructor called" << endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    cout << "Cure copy constructor called" << endl;
}

Cure& Cure::operator=(const Cure& other) {
    cout << "Cure operator = called" << endl;
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure() {
    cout << "Cure destructor called" << endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
