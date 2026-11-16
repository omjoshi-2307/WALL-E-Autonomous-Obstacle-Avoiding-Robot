// OOPVC Practical 4.3: Strategy design pattern
// File: system12.cpp
// ALGORITHM:
// 1. Define a payment strategy interface and concrete strategies.
// 2. Set each strategy in the shopping cart and execute checkout.

#include <iostream>
using namespace std;

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CreditCard : public PaymentStrategy {
public: void pay(int amt) override { cout << "Paid " << amt << " using Credit Card\n"; }
};
class UPI : public PaymentStrategy {
public: void pay(int amt) override { cout << "Paid " << amt << " using UPI\n"; }
};
class Cash : public PaymentStrategy {
public: void pay(int amt) override { cout << "Paid " << amt << " in Cash\n"; }
};

// Context
class ShoppingCart {
    PaymentStrategy *strategy;
public:
    ShoppingCart() : strategy(nullptr) {}
    void setStrategy(PaymentStrategy *s) { strategy = s; }
    void checkout(int amount) {
        if (strategy) strategy->pay(amount);
        else cout << "No payment method selected\n";
    }
};

int main() {
    ShoppingCart cart;
    CreditCard cc; UPI upi; Cash cash;

    cart.setStrategy(&cc);   cart.checkout(1500);
    cart.setStrategy(&upi);  cart.checkout(800);
    cart.setStrategy(&cash); cart.checkout(300);
    return 0;
}
