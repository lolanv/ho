// main.cpp
#include "functionalities.h"
#include <iostream>

int main() {
    try {
        std::vector<Order*> orders = createObjectsOnHeap();

        // Test cases for the functionalities
        std::cout << "Type of Order with ID 3: " << findTypeById(orders, 3) << std::endl;

        int lowestDiscountId = findLowestDiscountId(orders);
        std::cout << "ID of Order with Lowest Discount: " << lowestDiscountId << std::endl;

        std::cout << "Last 3 instances:" << std::endl;
        std::vector<Order*> lastThreeInstances = getLastNInstances(orders, 3);
        for (const auto& order : lastThreeInstances) {
            std::cout << "ID: " << order->getId() << ", Type: " << order->getType() << ", Discount: " << order->getDiscount() << std::endl;
        }

        // Delete objects and clear container
        deleteObjectsAndClear(orders);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
