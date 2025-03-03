#pragma once
#include <iostream>

using std::string;

class Brain{

    protected:

        string ideas[100];

    public:
    
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        virtual ~Brain();

        void setIdea(string _idea, int index);
        string getIdea(int index) const;

};