#pragma once

#include "trade.hpp"

class TradeHandle {
private:
    Trade* ptr;

public:
    explicit TradeHandle(Trade* p);
    ~TradeHandle();

    TradeHandle(const TradeHandle&) = delete;
    TradeHandle& operator=(const TradeHandle&) = delete;

    TradeHandle(TradeHandle&& other);
    TradeHandle& operator=(TradeHandle&& other);

    Trade* operator->();
    Trade& operator*();
};
