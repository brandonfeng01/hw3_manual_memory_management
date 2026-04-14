#include "trade.hpp"

Trade::Trade() : symbol(""), price(0.0) {
    std::cout << "Trade default created\n";
}

Trade::Trade(const std::string& s, double p) : symbol(s), price(p) {
    std::cout << "Trade created: " << symbol << "\n";
}

Trade::~Trade() {
    std::cout << "Trade destroyed: " << symbol << "\n";
}
