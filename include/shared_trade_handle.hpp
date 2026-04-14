#pragma once

#include "trade.hpp"

class SharedTradeHandle {
private:
    Trade* ptr;
    int* count;

    void release();

public:
    explicit SharedTradeHandle(Trade* p);
    ~SharedTradeHandle();

    SharedTradeHandle(const SharedTradeHandle& other);
    SharedTradeHandle& operator=(const SharedTradeHandle& other);

    Trade* operator->();
    Trade& operator*();
    int use_count() const;
};
