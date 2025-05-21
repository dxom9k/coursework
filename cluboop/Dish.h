#pragma once
#include <string>
#include <fstream>
using namespace std;

class Dish {
protected:
    int id;
    string s_id;
    string name;
    double weight;
    double price;

    ofstream cold_dish;
    ofstream author_dish;
    ofstream deserts;
    ofstream hookah;

    fstream ids;
    ofstream idss;

    char a;

public:
    void AddDish(int select);
    void GiveDish();

    ~Dish();
};
