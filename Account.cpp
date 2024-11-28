#include <iostream>
#include "Account.h"

Account::Account(const std::string& un, const std::string& st)
    : username(un), status(st) {}

Account::~Account() {
    std::cout << "Account removed.\n";
}

std::string Account::getStatus() const {
    return status;
}