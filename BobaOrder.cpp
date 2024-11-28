#include <iostream>
#include "BobaOrder.h"
#include "InvalidInput.h"  // Include the InvalidInput header
#include <stdexcept>

BobaOrder::BobaOrder(const std::string& n, const std::string& d, const std::string& p, float m, const std::string& sn)
    : DeliveryOrder(n, d, p, m), shopName(sn), drinksCount(0) {}

BobaOrder::~BobaOrder() {
    std::cout << "BobaOrder destroyed.\n";
}

void BobaOrder::receipt() const {
    DeliveryOrder::receipt();
    std::cout << "\tDrinks Count: " << drinksCount << "\n";
}

float BobaOrder::VIPdiscount() {
    if (drinksCount > 10) return 0.8f;  // Use float literals with 'f'
    else if (drinksCount > 5) return 0.9f;
    else if (drinksCount > 2) return 0.95f;
    else return 1.0f;
}

void BobaOrder::addDrink(const std::string& drink, bool addBoba, int count) {
    float price = 0.0f;
    if (drink == "Green Tea Latte") price = 5.8f;  // Use float literals
    else if (drink == "Brown Sugar Boba Milk") price = 7.8f;
    else if (drink == "Brown Sugar Pearl Milk") price = 9.8f;
    else throw InvalidInput(drink);  // InvalidInput is now recognized
    if (addBoba) price += 1.0f;  // Use float literal
    orderBalance += price * static_cast<float>(count);  // Optional cast for clarity
    drinksCount += count;
}