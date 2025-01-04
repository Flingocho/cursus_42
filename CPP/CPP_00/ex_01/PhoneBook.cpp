#include "PhoneBook.hpp"
#include <iostream>

void PhoneBook::addContact(Contact &contact) {
    contacts.push_back(contact);
}
