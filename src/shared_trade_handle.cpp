#include "shared_trade_handle.hpp"

void SharedTradeHandle::release() {
    if (control != nullptr) {
        --(control->count);
        if (control->count == 0) {
            delete control->ptr;
            delete control;
        }
        control = nullptr;
    }
}

SharedTradeHandle::SharedTradeHandle(Trade* p)
    : control(new ControlBlock(p)) {}

SharedTradeHandle::~SharedTradeHandle() {
    release();
}

SharedTradeHandle::SharedTradeHandle(const SharedTradeHandle& other)
    : control(other.control) {
    if (control != nullptr) {
        ++(control->count);
    }
}

SharedTradeHandle& SharedTradeHandle::operator=(const SharedTradeHandle& other) {
    if (this != &other) {
        release();
        control = other.control;
        if (control != nullptr) {
            ++(control->count);
        }
    }
    return *this;
}

Trade* SharedTradeHandle::operator->() {
    return control->ptr;
}

Trade& SharedTradeHandle::operator*() {
    return *(control->ptr);
}

int SharedTradeHandle::use_count() const {
    return control == nullptr ? 0 : control->count;
}
