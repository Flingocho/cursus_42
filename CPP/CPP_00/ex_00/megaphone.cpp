#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
    }
    else{
        std::string MyString;
        for (int i = 1; i < argc; i++) {
            MyString += argv[i];
        }
        for (std::string::size_type i = 0; i < MyString.size(); ++i) {
            MyString[i] = std::toupper(MyString[i]);
        }
        std::cout << MyString << std::endl;
    }
    return 0;
}
