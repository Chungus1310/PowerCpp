#include <iostream>
#include "FoodOrder.h"
#include "InvalidInput.h"  // Include the InvalidInput header
#include <stdexcept>

FoodOrder::FoodOrder(const std::string& n, const std::string& d, const std::string& p, float m, const std::string& rn)
    : DeliveryOrder(n, d, p, m), restaurantName(rn), foodCount(0) {}

FoodOrder::~FoodOrder() {
    std::cout << "FoodOrder destroyed.\n";
}

void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    std::cout << "\tFood Count: " << foodCount << "\n";
}

float FoodOrder::VIPdiscount() {
    if (orderBalance > 50.0f) return 0.8f;  // Use float literals with 'f'
    else if (orderBalance > 30.0f) return 0.9f;
    else if (orderBalance > 20.0f) return 0.95f;
    else return 1.0f;
}

void FoodOrder::addFood(const std::string& meal, int sides, bool addSoup) {
    float price = 0.0f;
    if (meal == "Thick Cauliflower Steaks") price = 15.0f;  // Use float literals
    else if (meal == "Rack of Lamb") price = 38.0f;
    else if (meal == "Organic Scottish Salmon") price = 23.0f;
    else if (meal == "Grilled Lobster Risotto") price = 46.0f;
    else throw InvalidInput(meal);  // InvalidInput is now recognized
    if (addSoup) price += 5.0f;  // Use float literal
    price += static_cast<float>(sides) * 6.0f;  // Explicit cast to float
    orderBalance += price;
    foodCount++;
}