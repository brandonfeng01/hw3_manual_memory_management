#include "shared_trade_handle.hpp"

void SharedTradeHandle::release() {
    if (count != nullptr) {
        --(*count);
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
}

SharedTradeHandle::SharedTradeHandle(Trade* p) : ptr(p), count(new int(1)) {}

SharedTradeHandle::~SharedTradeHandle() {
    release();
}

SharedTradeHandle::SharedTradeHandle(const SharedTradeHandle& other)
    : ptr(other.ptr), count(other.count) {
    ++(*count);
}

SharedTradeHandle& SharedTradeHandle::operator=(const SharedTradeHandle& other) {
    if (this != &other) {
        release();
        ptr = other.ptr;
        count = other.count;
        ++(*count);
    }
    return *this;
}

Trade* SharedTradeHandle::operator->() {
    return ptr;
}

Trade& SharedTradeHandle::operator*() {
    return *ptr;
}

int SharedTradeHandle::use_count() const {
    return count == nullptr ? 0 : *count;
}
