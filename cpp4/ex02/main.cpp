#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define RESET      "\033[0m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"


using std::cout;
using std::endl;

int	main(void)
{

cout << BG_BLUE << "Create and set ideas on dogs" << RESET << endl;
Dog dog1;
dog1.getBrain()->setIdea("I love bones!", 0);

Dog dog2 = dog1;
dog2.getBrain()->setIdea("I hate cats!", 0);

cout << endl;

cout << BG_BLUE << "Create and set ideas on cats" << RESET << endl;
Cat cat1;
cat1.getBrain()->setIdea("I love sleeping and eating!", 0);

Cat cat2 = cat1;
cat2.getBrain()->setIdea("I will bring doom  and pain upon humanity and make every living creature suffer before their most agonizing demise.", 0);

cout << endl;
cout << BG_BLUE << "Ensure deep copies:" << RESET << endl;

cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << endl;
cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << endl;
cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << endl;
cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << endl;

cout << endl;
cout << BG_BLUE << "Make sound no abstract class:" << RESET << endl;
dog1.makeSound();
cat1.makeSound();

cout << endl;
cout << BG_BLUE << "Array of cats and dogs creation:" << RESET << endl;

Animal* animals[10];

for (int i = 0; i < 10; i++){
    if (i % 2 == 0){
        animals[i] = new Dog();
        cout << endl;
    } else {
        animals[i] = new Cat();
        cout << endl;
    }
}

cout << endl;
cout << BG_BLUE << "Check they are well setted:" << RESET << endl;
for (int i = 0; i < 10; i++){
    if (i % 2 == 0){
        cout << "I am a " << animals[i]->getType() << endl;
    } else {
        cout << "I am a " << animals[i]->getType() << endl;
    }
}

cout << endl;
cout << BG_BLUE << "Delete callin animal destroyer" << RESET << endl;
for (int i = 0; i < 10; i++){
    delete animals[i];
}

cout << endl;
cout << BG_BLUE << "Stack auto destroyer" << RESET << endl;
    return (0);
}
