#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>

class DeliveryOrder {
protected:
    std::string name;
    std::string date;
    std::string phone;
    float miles;
    float orderBalance;
private:
    static int orderCount;
    static const float taxRate;
    static const float deliveryRate;
public:
    DeliveryOrder(const std::string& n, const std::string& d, const std::string& p, float m);
    virtual ~DeliveryOrder();
    virtual void receipt() const;
    virtual float getTotalBalance() const;
    static int getOrderCount();
    virtual float VIPdiscount() = 0;
};

#endif // DELIVERYORDER_H