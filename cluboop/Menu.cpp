#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void Menu::ShowMenu(int select) {
    ifstream* file = nullptr;
    string title;

    switch (select) {
    case 1: file = &show_cold_dishes; file->open("Author_dish.txt"); title = "Назва страви"; break; 
    case 2: file = &show_autor_dishes; file->open("Cold_Dish.txt"); title = "Назва страви"; break;
    case 3: file = &show_desetrs; file->open("Deserts.txt"); title = "Назва десерту"; break;
    case 4: file = &show_hookahes; file->open("Hookah.txt"); title = "Назва кальяну"; break;
    default: cout << "Невірний вибір меню." << endl; return;
    }

    if (!file->is_open()) {
        cout << "Помилка у відкритті файлу" << endl;
        return;
    }

    cout << setw(5) << left << "ID" << setw(20) << left << title << setw(10) << left << "Вага/Об'єм" << setw(10) << left << "Ціна" << endl << endl;
    while (getline(*file, str)) {
        cout << str << endl;
    }
    file->close();
}

void Menu::ShowAlcohol(int select) {
    ifstream* file = nullptr;
    switch (select) {
    case 1: file = &show_hard_drinks; file->open("Hard_Drinks.txt"); break;
    case 2: file = &show_soft_drinks; file->open("Soft_drinks.txt"); break;
    case 3: file = &show_beers; file->open("Beers.txt"); break;
    case 4: file = &show_coctails; file->open("Coctails.txt"); break;
    default: cout << "Невірний вибір напоїв." << endl; return;
    }

    if (!file->is_open()) {
        cout << "Помилка у відкритті файлу" << endl;
        return;
    }

    cout << setw(5) << left << "ID" << setw(20) << left << "Назва напою" << setw(10) << left << "Об'єм" << setw(10) << left << "Ціна" << endl << endl;
    while (getline(*file, str)) {
        cout << str << endl;
    }
    file->close();
}

void Menu::ShowBill() {
    show_bill.open("bill.txt");
    if (!show_bill.is_open()) {
        cout << "Помилка у відкритті рахунку" << endl;
        return;
    }

    cout << "Ваш рахунок:" << endl << endl;
    while (getline(show_bill, str)) {
        cout << str << endl;
    }
    show_bill.close();
}

double Menu::OrderDishes(int view, int id, int amount) {
    bill.open("bill.txt", ios::app);
    if (!bill.is_open()) {
        cout << "Не вдалося відкрити bill.txt" << endl;
        return 0;
    }

    ifstream* file = nullptr;
    switch (view) {
    case 1: file = &show_cold_dishes; file->open("Cold_Dish.txt"); break;
    case 2: file = &show_autor_dishes; file->open("Author_dish.txt"); break;
    case 3: file = &show_desetrs; file->open("Deserts.txt"); break;
    case 4: file = &show_hookahes; file->open("Hookah.txt"); break;
    default: return 0;
    }

    if (!file->is_open()) return 0;

    int i = 0;
    while (*file >> orders[i][0] >> orders[i][1] >> orders[i][2] >> orders[i][3]) {
        getline(*file, str); // дочитує решту рядка
        int current_id = stoi(orders[i][0]);
        if (id == current_id) {
            double price = stod(orders[i][3]);
            double total = price * amount;
            bill << str << endl;
            file->close();
            bill.close();
            return total;
        }
        ++i;
        if (i >= 100) break; // захист від виходу за межі
    }

    file->close();
    bill.close();
    return 0;
}

double Menu::OrderAlcohol(int select, int id, int amount) {
    bill.open("bill.txt", ios::app);
    if (!bill.is_open()) return 0;

    ifstream* file = nullptr;
    switch (select) {
    case 1: file = &show_hard_drinks; file->open("Hard_Drinks.txt"); break;
    case 2: file = &show_soft_drinks; file->open("Soft_drinks.txt"); break;
    case 3: file = &show_beers; file->open("Beers.txt"); break;
    case 4: file = &show_coctails; file->open("Coctails.txt"); break;
    default: return 0;
    }

    if (!file->is_open()) return 0;

    int i = 0;
    while (*file >> orders[i][0] >> orders[i][1] >> orders[i][2] >> orders[i][3]) {
        getline(*file, str); // дочитує решту рядка
        int current_id = stoi(orders[i][0]);
        if (id == current_id) {
            double price = stod(orders[i][3]);
            double total = price * amount;
            bill << str << endl;
            file->close();
            bill.close();
            return total;
        }
        ++i;
        if (i >= 100) break;
    }

    file->close();
    bill.close();
    return 0;
}
