#include "Ice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    cout << "* shoots an ice bolt at " << target.getName() << endl;
}
