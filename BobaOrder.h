#ifndef BOBOORDER_H
#define BOBOORDER_H

#include "DeliveryOrder.h"
#include <string>

class BobaOrder : public DeliveryOrder {
private:
    std::string shopName;
    int drinksCount;
public:
    BobaOrder(const std::string& n, const std::string& d, const std::string& p, float m, const std::string& sn);
    ~BobaOrder();
    void receipt() const override;
    float VIPdiscount() override;
    void addDrink(const std::string& drink, bool addBoba = true, int count = 1);
};

#endif // BOBOORDER_H