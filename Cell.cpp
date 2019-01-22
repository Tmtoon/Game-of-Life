//
// Created by tmtoon on 22.01.19.
//

#include "Cell.h"
#include <ostream>

std::string DeadCell::str() const {
    return " ";
}

bool DeadCell::alive() const {
    return false;
}

std::string AliveCell::str() const {
    return "*";
}

bool AliveCell::alive() const {
    return true;
}

std::ostream &operator<<(std::ostream &os, const Cell &c) {
    os << c.str();
    return os;
}
