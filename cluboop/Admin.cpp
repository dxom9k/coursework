#include "Admin.h"
#include <iostream>
#include <conio.h>  // для _getch()
#include <windows.h>  // для Sleep()
using namespace std;

bool Admin::Entrence() {
    cout << "Введіть пароль: ";
    cin >> CheckPassword;
    return CheckPassword == password;
}

void Admin::ChangeWiFiPassword() {
    SetWiFiPASS();
    cout << "Введіть старий пароль: ";
    cin >> CheckPassword;

    ofstream WiFi("WiFiPassword.txt");

    if (CheckPassword == WiFiPassword) {
        cout << "Введіть новий пароль: ";
        cin >> NewWiFiPassword;
        system("cls");
        cout << "Повторіть пароль: ";
        cin >> NewWiFiPassword1;

        if (NewWiFiPassword == NewWiFiPassword1) {
            WiFiPassword = NewWiFiPassword1;
            WiFi << NewWiFiPassword1;
        }
        else {
            cout << "Ви ввели не однакові паролі!!!" << endl;
        }
    }
    else {
        cout << "!!!Ви ввели неправильний пароль!!!" << endl;
    }
    WiFi.close();
}

void Admin::ChangeWorkHours() {
    WorkHours.open("WorkHours.txt");

    if (WorkHours.is_open()) {
        cout << "Введіть нові години роботи: ";
        NewWorkHours.clear(); // очищаємо попередні дані
        do {
            a = _getch();
            if ((int)a != 13) {  // Enter
                cout << (char)a;
                NewWorkHours.push_back(a);
            }
        } while ((int)a != 13);

        for (char ch : NewWorkHours) {
            WorkHours << ch;
        }
    }
    else {
        cout << "Не вдалося відкрити файл WorkHours.txt!" << endl;
    }

    WorkHours.close();
}

void Admin::ChangeEntrancePrice() {
    EntrancePriceFile.open("EntrencePrice.txt", ios::out);

    if (!EntrancePriceFile.is_open()) {
        cout << "Помилка у відкриті файла!!!" << endl;
    }
    else {
        system("cls");
        cout << "Введіть нову ціну за вхід: ";
        cin >> EntrancePrice;
        EntrancePriceFile << "Ціна за вхід -- " << EntrancePrice << " грн.";
        EntrancePriceFile.close();
    }
}

void Admin::OrderProducts() {
    cout << "Введіть назву продукту: ";
    cin >> Products;
    cout << "Введіть кількість: ";
    cin >> number;
    system("cls");
    cout << "\n\n\n\t\t\tПродукти замовлено" << endl;
    Sleep(3000);
}

Admin::~Admin() {
    if (WiFi.is_open()) WiFi.close();
    if (WorkHours.is_open()) WorkHours.close();
    if (EntrancePriceFile.is_open()) EntrancePriceFile.close();
}
