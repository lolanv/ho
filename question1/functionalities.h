// functionalities.h
#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "order.h"

std::vector<Order*> createObjectsOnHeap();
std::string findTypeById(const std::vector<Order*>& orders, int id);
int findLowestDiscountId(const std::vector<Order*>& orders);
std::vector<Order*> getLastNInstances(const std::vector<Order*>& orders, int n);
void deleteObjectsAndClear(std::vector<Order*>& orders);

#endif // FUNCTIONALITIES_H
