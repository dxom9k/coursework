#pragma once
#include <string>
#include <fstream>
using namespace std;

class Drinks {
protected:
    int id;
    double capacity, price;
    string name, s_id;

    ofstream hard_drinks;
    ofstream soft_drinks;
    ofstream beers;
    ofstream coctails;
    ofstream idss;

    fstream ids;

public:
    void AddDirnk(int select);
    void GiveDrinkh();

    ~Drinks();
};
