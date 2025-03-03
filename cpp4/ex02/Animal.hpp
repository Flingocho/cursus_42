#pragma once
#include <string>
#include <iostream>

using std::string;

class Animal {

    protected:
        string type;

    public:
        Animal(void);
        Animal(string _type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        string getType() const;
        void setType(string _type);

        virtual void makeSound() const = 0;
};
