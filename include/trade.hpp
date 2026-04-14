#pragma once

#include <iostream>
#include <string>

struct Trade {
    std::string symbol;
    double price;

    Trade();
    Trade(const std::string& s, double p);
    ~Trade();
};
