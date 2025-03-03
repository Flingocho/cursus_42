#include "Animal.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

Animal::Animal(void){
    cout << "No type Animal constructor called" << endl;
};

Animal::Animal(string _name) : type(_name) {
    cout << type << " Animal constructor called" << endl;
};

Animal::Animal(const Animal& other) : type(other.type) {
    cout << "Animal copy constructor called" << endl;
}

Animal& Animal::operator=(const Animal& other){
    cout << "Animal operator = called" << endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal(){
    cout << "Animal destructor called" << endl;
}

string Animal::getType() const {
    return(type);
}

void Animal::setType(string _type){
    this->type = _type;
}