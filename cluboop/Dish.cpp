#include "Dish.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;

void Dish::AddDish(int select) {
    system("cls");

    ids.open("ids.txt");
    getline(ids, s_id);
    id = atoll(s_id.c_str());

    if (select == 1) {
        author_dish.open("Author_dish.txt", ofstream::app);
        if (!author_dish.is_open()) {
            cout << "Помилка у відкриті файлу" << endl;
        }
        else {
            cout << "Введіть назву страви: ";
            cin >> name;
            cout << "Введіть вагу страви: ";
            cin >> weight;
            cout << "Введіть ціну страви: ";
            cin >> price;

            author_dish << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << weight << " "
                << setw(10) << left << price << endl;

            author_dish.close();
        }
    }

    if (select == 2) {
        cold_dish.open("Cold_Dish.txt", ofstream::app);
        if (!cold_dish.is_open()) {
            cout << "Помилка у відкриті файлу" << endl;
        }
        else {
            cout << "Введіть назву страви: ";
            cin >> name;
            cout << "Введіть вагу страви: ";
            cin >> weight;
            cout << "Введіть ціну страви: ";
            cin >> price;

            cold_dish << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << weight << " "
                << setw(10) << left << price << endl;

            cold_dish.close();
        }
    }

    if (select == 3) {
        deserts.open("Deserts.txt", ofstream::app);
        if (!deserts.is_open()) {
            cout << "Помилка у відкриті файлу" << endl;
        }
        else {
            cout << "Введіть назву десерту: ";
            cin >> name;
            cout << "Введіть вагу десерту: ";
            cin >> weight;
            cout << "Введіть ціну десерту: ";
            cin >> price;

            deserts << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << weight << " "
                << setw(10) << left << price << endl;

            deserts.close();
        }
    }

    if (select == 4) {
        hookah.open("Hookah.txt", ofstream::app);
        if (!hookah.is_open()) {
            cout << "Помилка у відкриті файлу" << endl;
        }
        else {
            cout << "Введіть назву кальяну: ";
            cin >> name;
            cout << "Введіть ціну кальяну: ";
            cin >> price;

            hookah << setw(5) << left << id << " "
                << setw(20) << left << name << " "
                << setw(10) << left << price << endl;

            hookah.close();
        }
    }

    ids.close();
    idss.open("ids.txt", ofstream::trunc);
    id++;
    idss << id;
    idss.close();
}

void Dish::GiveDish() {
    system("cls");
    cout << "\n\n\n\t\t\tВаше замовлення подано" << endl;
    Sleep(3000);
}

Dish::~Dish() {
    if (cold_dish.is_open()) cold_dish.close();
    if (author_dish.is_open()) author_dish.close();
    if (hookah.is_open()) hookah.close();
    if (deserts.is_open()) deserts.close();
}
