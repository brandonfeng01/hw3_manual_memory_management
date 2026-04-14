#include "trade_handle.hpp"
#include <utility>

TradeHandle::TradeHandle(Trade* p) : ptr(p) {}

TradeHandle::~TradeHandle() {
    delete ptr;
}

TradeHandle::TradeHandle(TradeHandle&& other) : ptr(other.ptr) {
    other.ptr = nullptr;
}

TradeHandle& TradeHandle::operator=(TradeHandle&& other) {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

Trade* TradeHandle::operator->() {
    return ptr;
}

Trade& TradeHandle::operator*() {
    return *ptr;
}
