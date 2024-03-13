// order.h
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

class Order {

private:
    int _id;
    std::string _type;
    double _discount;
    
public:
    Order(int id, std::string type, double discount);

    int getId() const;
    std::string getType() const;
    double getDiscount() const;
};

#endif // ORDER_H
