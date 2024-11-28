#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include <string>

class FoodOrder : public DeliveryOrder {
private:
    std::string restaurantName;
    int foodCount;
public:
    FoodOrder(const std::string& n, const std::string& d, const std::string& p, float m, const std::string& rn);
    ~FoodOrder();
    void receipt() const override;
    float VIPdiscount() override;
    void addFood(const std::string& meal, int sides = 0, bool addSoup = false);
};

#endif // FOODORDER_H