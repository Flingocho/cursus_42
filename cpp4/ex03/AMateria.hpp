#pragma once
#include <iostream>

using std::string;

class ICharacter;

class AMateria{

    protected:

        string type;


    public:

    AMateria();
    AMateria(string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    void setType(string _type);
    string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

};