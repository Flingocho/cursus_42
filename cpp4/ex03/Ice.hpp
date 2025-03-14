#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

using std::string;

class Ice : public AMateria{

    public:

        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);

};