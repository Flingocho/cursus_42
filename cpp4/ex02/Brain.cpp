#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain(){
    cout << "Brain constructor called" << endl;
}

Brain::Brain(const Brain& other){

    cout << "Brain copy constructor called" << endl;
    for (int i = 0; i < 100; i++){
        ideas[i] = other.ideas[i];
    } 
}

Brain& Brain::operator=(const Brain& other){
    cout << "Brain operator = called" << endl;
    if(this != &other){
        for (int i = 0; i < 100; i++){
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(){
    cout << "Brain destructor called" << endl;
}

void Brain::setIdea(string _idea, int index){
    if(index >= 0 && index < 100){
        cout << "New idea: " << _idea << endl;
        this->ideas[index] = _idea;
    } else {
        cout << "Invalid parameters for new idea" << endl;
    }
        
}

string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "Invalid index";
}
