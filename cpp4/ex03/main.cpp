#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

using std::cout;
using std::endl;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main() {
    cout << CYAN << "Creating MateriaSource..." << RESET << endl;
    IMateriaSource* materiaSource = new MateriaSource();

    cout << CYAN << "Learning Ice and Cure Materias..." << RESET << endl;
    materiaSource->learnMateria(new Ice());
    materiaSource->learnMateria(new Cure());

    cout << CYAN << "Creating a Character..." << RESET << endl;
    ICharacter* player = new Character("Player1");

    cout << CYAN << "Creating Materias using MateriaSource..." << RESET << endl;
    AMateria* iceMateria = materiaSource->createMateria("ice");
    AMateria* cureMateria = materiaSource->createMateria("cure");

    cout << GREEN << "Equipping Ice Materia..." << RESET << endl;
    player->equip(iceMateria);

    cout << GREEN << "Equipping Cure Materia..." << RESET << endl;
    player->equip(cureMateria);

    cout << BLUE << "Using Ice Materia on self..." << RESET << endl;
    player->use(0, *player);

    cout << BLUE << "Using Cure Materia on self..." << RESET << endl;
    player->use(1, *player);

    cout << RED << "Unequipping Ice Materia..." << RESET << endl;
    player->unequip(0);

    cout << CYAN << "Equipping a new Ice Materia..." << RESET << endl;
    AMateria* newIceMateria = materiaSource->createMateria("ice");
    player->equip(newIceMateria);

    cout << RED << "Cleaning up..." << RESET << endl;
    delete materiaSource;
    delete player;


    cout << GREEN << "All tests completed successfull" << RESET << endl;
    return 0;
}
