#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

using std::string;

class Character : public ICharacter {

    private:

        string name;
        AMateria* inventory[4];
        AMateria* dropped[100];
        int droppedCount;

    public:

        Character(string _name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        virtual string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);

};