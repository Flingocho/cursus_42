#include <iostream>
#include "Character.hpp"

using std::string;
using std::cout;
using std::endl;

Character::Character(string _name) : name(_name), droppedCount(0) {
    cout << "Character constructor called (" << name << ")" << endl;
    
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++) {
        dropped[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name), droppedCount(other.droppedCount) {
    cout << "Character copy constructor called" << endl;

    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i];
        else
            inventory[i] = NULL;
    }

    for (int i = 0; i < 100; i++) {
        if (i < droppedCount && other.dropped[i]) 
            dropped[i] = other.dropped[i];  
        else
            dropped[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}


Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
    for (int i = 0; i < droppedCount; i++) {
        delete dropped[i];
    }
}




string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            cout << name << " equipped " << m->getType() << endl;
            return;
        }
    }
    cout << name << "'s inventory is full! Cannot equip " << m->getType() << endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) return;

    if (droppedCount < 100) {
        cout << "Unequipping " << inventory[idx]->getType() << " and storing in dropped[" << droppedCount << "]" << endl;
        dropped[droppedCount++] = inventory[idx];
    }

    inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) {
        cout << "No materia in slot " << idx << " to use." << endl;
        return;
    }
    inventory[idx]->use(target);
}
