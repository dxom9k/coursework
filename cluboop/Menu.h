#pragma once
#include "Dish.h"
#include "Drinks.h"
#include <string>
#include <fstream>
using namespace std;

class Menu : public Dish, public Drinks {
private:
    string str;

    ifstream show_hard_drinks;
    ifstream show_soft_drinks;
    ifstream show_beers;
    ifstream show_coctails;

    ifstream show_cold_dishes;
    ifstream show_autor_dishes;
    ifstream show_desetrs;
    ifstream show_hookahes;

    ifstream show_bill;
    ofstream bill;

    string orders[100][4];
    int idt;
    int s_price;

public:
    void ShowMenu(int select);
    void ShowAlcohol(int select);
    void ShowBill();

    double OrderDishes(int select, int id, int amount);
    double OrderAlcohol(int select, int id, int amount);
};
