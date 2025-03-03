#include "IMateriaSource.hpp"
#include <iostream>

using std::cout;
using std::endl;

IMateriaSource::IMateriaSource() {
    cout << "IMateriaSource default constructor called" << endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
    (void)other;
    cout << "IMateriaSource copy constructor called" << endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
    (void)other;
    cout << "IMateriaSource assignment operator called" << endl;
    return *this;
}

IMateriaSource::~IMateriaSource() {
    cout << "IMateriaSource destructor called" << endl;
}
