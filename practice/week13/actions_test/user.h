#pragma once
#include <string>

struct User {
    std::string name;
    int hp;
};

void printStatus(const User& user);