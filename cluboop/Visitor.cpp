#include "Visitor.h"
#include <iostream>
#include <conio.h>     // _getch()
#include <windows.h>   // Sleep()
#include <iomanip>     // setw()
using namespace std;

Visitor::Visitor(int age, double balance, double card_balance) {
    this->age = age;
    this->balance = balance;
    this->card_balance = card_balance;
}

void Visitor::OrderSong() {
    if (balance >= 200) {
        cout << "Введіть назву пісні: ";
        song.clear();
        do {
            a = _getch();
            if ((int)a != 13) {
                cout << (char)a;
                song.push_back(a);
            }
        } while ((int)a != 13);

        system("cls");
        cout << endl << endl << endl;
        cout << "\t\t\t*тиц - тиц - тиц*" << endl;
        cout << "\t\t\tЗараз грає: ";
        for (char ch : song) cout << ch;
        cout << endl;
        cout << "\t\t\t*тиц - тиц - тиц*" << endl;
        Sleep(5000);
        balance -= 200;
    }
    else {
        cout << "\n\n\n\t\t\t!!!У вас недостатньо коштів!!!";
    }
}

string Visitor::GetWorkHours() {
    Hours.open("WorkHours.txt");
    if (!Hours.is_open()) return "ERROR 404";

    getline(Hours, s_Hours);
    Hours.close();
    return s_Hours;
}

void Visitor::BookTable() {
    system("cls");
    cout << "Кількість столиків: 15" << endl << endl << endl;
    cout << "Заброньовані столики: " << endl;
    for (int num : tables) cout << "Cтолик №" << num << endl;

    cout << endl << endl << endl;

    while (true) {
        cout << "Введіть номер столика, який ви б хотіли забронювати: ";
        cin >> a;

        bool isTaken = false;
        for (int num : tables) {
            if (num == a) {
                isTaken = true;
                break;
            }
        }

        if (isTaken) {
            cout << "\n\n\n\t\t\tСтолик вже заброньований" << endl << endl << endl;
            Sleep(2000);
            system("cls");
        }
        else {
            tables.push_back(a);
            system("cls");
            cout << "\n\n\n\t\t\t Ви забронювали столик №" << a << endl;
            break;
        }
    }
}

void Visitor::LeavFeedBack() {
    o_LeaveFeedback.open("Feedback.txt", ios::app);
    if (!o_LeaveFeedback.is_open()) {
        cout << "Помилка у відкриті файлу" << endl;
        return;
    }

    system("cls");
    cout << "Введіть своє ім'я: ";
    cin >> name;
    cout << "Введіть кількість зірочок 1 - 5: ";
    cin >> stars;

    if (stars > 5) stars = 5;
    if (stars < 0) stars = 0;

    cout << "Опишіть клуб одним словом: ";
    cin >> coment;

    o_LeaveFeedback << setw(15) << left << name << " | ";
    o_LeaveFeedback << setw(14) << left;

    for (int i = 0; i < stars; ++i) o_LeaveFeedback << "*";
    o_LeaveFeedback << " | ";
    o_LeaveFeedback << coment << endl;

    o_LeaveFeedback.close();
}
