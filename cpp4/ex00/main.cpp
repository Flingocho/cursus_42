#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main(void)
{
    std::cout << CYAN << "\n=== TEST 1: Animal Hierarchy ===" << RESET << std::endl;
    const Animal* animal = new Animal();
    animal->makeSound();

    std::cout << GREEN << "\n=== TEST 2: Dog Sound ===" << RESET << std::endl;
    Animal* dog = new Dog();
    dog->makeSound();

    std::cout << YELLOW << "\n=== TEST 3: Cat Sound ===" << RESET << std::endl;
    const Animal* cat = new Cat();
    cat->makeSound();

    std::cout << BLUE << "\n=== TEST 4: WrongAnimal Sound ===" << RESET << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    wrongAnimal->makeSound();

    std::cout << MAGENTA << "\n=== TEST 5: WrongCat Sound (Object) ===" << RESET << std::endl;
    WrongCat wrongCat;
    wrongCat.makeSound();

    std::cout << RED << "\n=== TEST 6: WrongAnimal* pointing to WrongCat ===" << RESET << std::endl;
    const WrongAnimal* wrongPtr = new WrongCat();
    wrongPtr->makeSound();

    std::cout << WHITE << "\n=== TEST 7: Cleaning up ===" << RESET << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongPtr;
    return (0);
}
