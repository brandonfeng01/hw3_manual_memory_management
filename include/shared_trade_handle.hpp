#pragma once

#include "trade.hpp"

struct ControlBlock {
    Trade* ptr;
    int count;

    explicit ControlBlock(Trade* p) : ptr(p), count(1) {}
};

class SharedTradeHandle {
private:
    ControlBlock* control;

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
