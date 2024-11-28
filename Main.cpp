#include <iostream>
#include <iomanip>
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"
#include "InvalidInput.h"

float applyDiscount(DeliveryOrder* order, const Account& account) {
    float totalBalance = order->getTotalBalance();
    if (account.getStatus() == "Owner") {
        return totalBalance * 0.9f; // Use float literal
    } else if (account.getStatus() == "VIP") {
        return totalBalance * (1.0f - order->VIPdiscount()); // Use float literal
    } else {
        return 0.0f; // Use float literal
    }
}

int main() {
    Account stuart("Stuart", "Owner");
    Account kevin("Kevin", "VIP");
    Account bob("Bob");

    DeliveryOrder* order;

    // Kevin placing order
    std::cout << "Kevin is placing order.\n";
    BobaOrder* kevinOrder = new BobaOrder("Kevin", "04/20/2024", "123-456-0000", 10.4f, "M Tea"); // Use float literal
    try {
        kevinOrder->addDrink("Green Tea Latte");
        kevinOrder->addDrink("Brown Sugar Pearl Milk", false);
        kevinOrder->addDrink("Brown Sugar Boba Milk", false, 2);
        kevinOrder->addDrink("Iron Goddess");
    } catch (const InvalidInput& e) {
        e.reason();
        std::cout << "Not serving requested drinks. Drink order ignored.\n\n";
    }
    order = kevinOrder;
    std::cout << std::fixed << std::setprecision(2);
    order->receipt();
    float balance = order->getTotalBalance();
    std::cout << "Balance: $" << balance << "\n";
    float discount = applyDiscount(order, kevin);
    std::cout << "Discounted Balance: $" << (balance - discount) << "\n";
    std::cout << "\n\n";

    // Stuart placing order
    std::cout << "Stuart is placing order.\n";
    FoodOrder* stuartOrder = new FoodOrder("Stuart", "04/20/2024", "123-456-1111", 25.5f, "Tavern Green"); // Use float literal
    try {
        stuartOrder->addFood("Thick Cauliflower Steaks", 1, true);
        stuartOrder->addFood("Organic Scottish Salmon");
        stuartOrder->addFood("Rack of Lamb", 0, true);
    } catch (const InvalidInput& e) {
        e.reason();
        std::cout << "Not serving requested food. Food order ignored.\n\n";
    }
    order = stuartOrder;
    order->receipt();
    balance = order->getTotalBalance();
    std::cout << "Balance: $" << balance << "\n";
    discount = applyDiscount(order, stuart);
    std::cout << "Discounted Balance: $" << (balance - discount) << "\n";
    std::cout << "\n\n";

    // Bob attempting to place order
    std::cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
    order = stuartOrder;
    order->receipt();
    balance = order->getTotalBalance();
    std::cout << "Balance: $" << balance << "\n";
    discount = applyDiscount(order, bob);
    std::cout << "Discounted Balance: $" << (balance - discount) << "\n";
    std::cout << "Bob upset, cancelling order :(\n\n";

    // Total orders placed
    std::cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

    delete kevinOrder;
    delete stuartOrder;

    // Add a pause to keep the console window open
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}