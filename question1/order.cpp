// order.cpp
#include "order.h"

Order::Order(int id, std::string type, double discount)
    : _id(id), _type(std::move(type)), _discount(discount) {}

int Order::getId() const {
    return _id;
}

std::string Order::getType() const {
    return _type;
}

double Order::getDiscount() const {
    return _discount;
}
