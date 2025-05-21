#pragma once
#include <string>
#include <fstream>
using namespace std;

class Human {
protected:
    int age;
    double balance, card_balance;
    string WiFiPassword;
    ifstream Pass;
    ifstream WiFi;
    fstream Feedback;
    string Feedbacks;

    void SetWiFiPASS();

public:
    virtual ~Human();

    void OrderDish();
    void ReadFeedback();

    double GetBalance();
    double GetCardBalance();

    void SetBalance(double balance);
    void SetCardBalance(double card_balance);

    string GetWiFiPassword();
};
