// functionalities.cpp
#include "functionalities.h"
#include <algorithm>

std::vector<Order*> createObjectsOnHeap() {
    std::vector<Order*> orders;
    for (int i = 1; i <= 5; ++i) {
        orders.push_back(new Order(i, "Type" + std::to_string(i), 0.1 * i));
    }
    return orders;
}

std::string findTypeById(const std::vector<Order*>& orders, int id) {
    for (const auto& order : orders) {
        if (order->getId() == id) {
            return order->getType();
        }
    }
    throw std::runtime_error("Order with given ID not found");
}

int findLowestDiscountId(const std::vector<Order*>& orders) {
    if (orders.empty()) {
        throw std::runtime_error("Empty container");
    }

    int lowestId = orders[0]->getId();
    double lowestDiscount = orders[0]->getDiscount();

    for (const auto& order : orders) {
        if (order->getDiscount() < lowestDiscount) {
            lowestId = order->getId();
            lowestDiscount = order->getDiscount();
        }
    }

    return lowestId;
}

std::vector<Order*> getLastNInstances(const std::vector<Order*>& orders, int n) {
    int size = orders.size();
    if (n <= 0 || size == 0) {
        throw std::runtime_error("Invalid input for getLastNInstances");
    }

    return (n <= size) ? std::vector<Order*>(orders.end() - n, orders.end()) : orders;
}

void deleteObjectsAndClear(std::vector<Order*>& orders) {
    for (const auto& order : orders) {
        delete order;
    }
    orders.clear();
}
