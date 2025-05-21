#include "Drinks.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void Drinks::AddDirnk(int select) {
    ids.open("ids.txt");
    getline(ids, s_id);
    id = atoll(s_id.c_str());

    cout << "Введіть назву напою: ";
    cin >> name;
    cout << "Введіть об'єм напою (мл): ";
    cin >> capacity;
    cout << "Введіть ціну напою: ";
    cin >> price;

    switch (select) {
    case 1:
        system("cls");
        hard_drinks.open("Hard_Drinks.txt", ofstream::app);
        if (!hard_drinks.is_open()) {
            cout << "Помилка у відкритті файлу" << endl;
        }
        else {
            hard_drinks << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << capacity << " "
                << setw(10) << left << price << endl;
            hard_drinks.close();
        }
        break;

    case 2:
        system("cls");
        soft_drinks.open("Soft_Drinks.txt", ofstream::app);
        if (!soft_drinks.is_open()) {
            cout << "Помилка у відкритті файлу" << endl;
        }
        else {
            soft_drinks << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << capacity << " "
                << setw(10) << left << price << endl;
            soft_drinks.close();
        }
        break;

    case 3:
        system("cls");
        beers.open("Beers.txt", ofstream::app);
        if (!beers.is_open()) {
            cout << "Помилка у відкритті файлу" << endl;
        }
        else {
            beers << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << capacity << " "
                << setw(10) << left << price << endl;
            beers.close();
        }
        break;

    case 4:
        system("cls");
        coctails.open("Coctails.txt", ofstream::app);
        if (!coctails.is_open()) {
            cout << "Помилка у відкритті файлу" << endl;
        }
        else {
            coctails << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << capacity << " "
                << setw(10) << left << price << endl;
            coctails.close();
        }
        break;

    default:
        cout << "Невірний вибір категорії напоїв!" << endl;
        break;
    }

    ids.close();
    id++;
    idss.open("ids.txt", ofstream::trunc);
    idss << id;
    idss.close();
}

void Drinks::GiveDrinkh() {
    system("cls");
    cout << "\n\n\n\t\t\tВаш напій подано" << endl;
    Sleep(3000);
}

Drinks::~Drinks() {
    if (hard_drinks.is_open()) hard_drinks.close();
    if (soft_drinks.is_open()) soft_drinks.close();
    if (beers.is_open()) beers.close();
    if (coctails.is_open()) coctails.close();
    if (ids.is_open()) ids.close();
    if (idss.is_open()) idss.close();
}
