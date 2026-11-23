#include "user.h"
#include <iostream>

void printStatus(const User& user) {
    std::cout << user.name << " HP: " << user.hp << '\n';
}