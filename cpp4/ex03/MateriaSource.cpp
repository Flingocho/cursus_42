#include "MateriaSource.hpp"
#include <iostream>

using std::cout;
using std::endl;

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.templates[i])
            templates[i] = other.templates[i];
        else
            templates[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete templates[i];
            templates[i] = (other.templates[i]) ? other.templates[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) return;

    for (int i = 0; i < 4; i++) {
        if (!templates[i]) {
            templates[i] = materia;
            cout << "Learned " << materia->getType() << endl;
            return;
        }
    }
    cout << "MateriaSource is full, can't learn " << materia->getType() << endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    cout << "Unknown Materia: " << type << endl;
    return 0;
}
