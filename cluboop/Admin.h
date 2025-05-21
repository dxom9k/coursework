#pragma once
#include "Human.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Admin : public Human {
private:
    string password = "5955";
    string CheckPassword;
    string NewWiFiPassword, NewWiFiPassword1;

    ofstream WorkHours;
    string c_WorkHours;

    double EntrancePrice;
    fstream EntrancePriceFile;

    vector<char> NewWorkHours;
    char a;

    string Products;
    int number;

public:
    bool Entrence();
    void ChangeWiFiPassword();
    void ChangeWorkHours();
    void ChangeEntrancePrice();
    void OrderProducts();

    ~Admin();
};
