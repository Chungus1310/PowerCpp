#include <iostream>
#include "DeliveryOrder.h"
#include <iostream>

int DeliveryOrder::orderCount = 0;
const float DeliveryOrder::taxRate = 0.09f;  // Use float literal
const float DeliveryOrder::deliveryRate = 2.0f;  // Use float literal

DeliveryOrder::DeliveryOrder(const std::string& n, const std::string& d, const std::string& p, float m)
    : name(n), date(d), phone(p), miles(m), orderBalance(0.0f) {  // Use float literal
    orderCount++;
}

DeliveryOrder::~DeliveryOrder() {
    std::cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {
    std::cout << "Order Detail:\n";
    std::cout << "\tName: " << name << "\n";
    std::cout << "\tDate: " << date << "\n";
    std::cout << "\tPhone: " << phone << "\n";
    std::cout << "\tOrder Balance: $" << orderBalance << "\n";
}

float DeliveryOrder::getTotalBalance() const {
    return orderBalance * (1.0f + taxRate) + miles * deliveryRate;  // Use float literals
}

int DeliveryOrder::getOrderCount() {
    return orderCount;
}