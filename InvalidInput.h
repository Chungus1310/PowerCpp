#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>
#include <iostream>

class InvalidInput {
private:
    const std::string message;
public:
    InvalidInput(const std::string& input)
        : message("Invalid input \"" + input + "\".\n") {}
    void reason() const {
        std::cout << message;
    }
};

#endif // INVALIDINPUT_H