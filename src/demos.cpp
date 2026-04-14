#include "demos.hpp"
#include "trade.hpp"
#include "trade_handle.hpp"
#include "shared_trade_handle.hpp"

#include <iostream>
#include <utility>

void run_part1() {
    std::cout << "\n===== Part 1 =====\n";

    Trade* t = new Trade("AAPL", 150.0);
    std::cout << t->symbol << " " << t->price << "\n";
    delete t;

    Trade* arr = new Trade[5];
    arr[0] = Trade("AAPL", 150.0);
    arr[1] = Trade("GOOG", 2800.0);
    arr[2] = Trade("MSFT", 300.0);
    arr[3] = Trade("TSLA", 750.0);
    arr[4] = Trade("NVDA", 900.0);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i].symbol << " " << arr[i].price << "\n";
    }

    delete[] arr;
}

void run_part2() {
    std::cout << "\n===== Part 2 =====\n";

    Trade* t1 = new Trade("AAPL", 150.0);
    Trade* t2 = new Trade("GOOG", 2800.0);

    delete t1;
    t1 = nullptr;

    Trade* t3 = new Trade("MSFT", 300.0);
    delete t3;
    t3 = new Trade("TSLA", 750.0);

    Trade* trades = new Trade[3]{
        {"NVDA", 900.0},
        {"AMZN", 3200.0},
        {"META", 250.0}
    };

    delete t2;
    delete t3;
    delete[] trades;
}

void run_part3() {
    std::cout << "\n===== Part 3 =====\n";

    TradeHandle h1(new Trade("IBM", 135.0));
    std::cout << h1->symbol << " " << h1->price << "\n";

    TradeHandle h2(new Trade("ORCL", 120.0));
    std::cout << (*h2).symbol << " " << (*h2).price << "\n";

    TradeHandle h3(std::move(h2));
    std::cout << h3->symbol << " " << h3->price << "\n";
}

void run_part4() {
    std::cout << "\n===== Part 4 =====\n";

    SharedTradeHandle h1(new Trade("NFLX", 620.0));
    std::cout << "count: " << h1.use_count() << "\n";

    {
        SharedTradeHandle h2 = h1;
        std::cout << h2->symbol << " " << h2->price << "\n";
        std::cout << "count: " << h1.use_count() << "\n";
    }

    std::cout << "count: " << h1.use_count() << "\n";
}

void run_part5() {
    std::cout << "\n===== Part 5 =====\n";
}
