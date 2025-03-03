#include "AMateria.hpp"

using std::cout;
using std::endl;

AMateria::AMateria() : type("") {
    cout << "AMateria constructor called" << endl;
}

AMateria::AMateria(string const & type) : type(type) {
    cout << "AMateria parameterized constructor called" << endl;
}

AMateria::AMateria(const AMateria& other){
    cout << "AMateria copy constructor called" << endl;
    type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other){
    cout << "AMateria operator = called" << endl;
    if(this != &other){
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria(){
    cout << "AMateria destructor called" << endl;
}

string const & AMateria::getType() const {
    return type;
}

void AMateria::setType(string _type){
    this->type = _type;
}
