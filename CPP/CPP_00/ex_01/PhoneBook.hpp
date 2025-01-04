#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <vector>
#include "Contact.hpp"

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(Contact &contact);
};
#endif