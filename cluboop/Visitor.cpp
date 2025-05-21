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
        cout << "������ ����� ���: ";
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
        cout << "\t\t\t*��� - ��� - ���*" << endl;
        cout << "\t\t\t����� ���: ";
        for (char ch : song) cout << ch;
        cout << endl;
        cout << "\t\t\t*��� - ��� - ���*" << endl;
        Sleep(5000);
        balance -= 200;
    }
    else {
        cout << "\n\n\n\t\t\t!!!� ��� ����������� �����!!!";
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
    cout << "ʳ������ �������: 15" << endl << endl << endl;
    cout << "����������� �������: " << endl;
    for (int num : tables) cout << "C����� �" << num << endl;

    cout << endl << endl << endl;

    while (true) {
        cout << "������ ����� �������, ���� �� � ����� �����������: ";
        cin >> a;

        bool isTaken = false;
        for (int num : tables) {
            if (num == a) {
                isTaken = true;
                break;
            }
        }

        if (isTaken) {
            cout << "\n\n\n\t\t\t������ ��� �������������" << endl << endl << endl;
            Sleep(2000);
            system("cls");
        }
        else {
            tables.push_back(a);
            system("cls");
            cout << "\n\n\n\t\t\t �� ����������� ������ �" << a << endl;
            break;
        }
    }
}

void Visitor::LeavFeedBack() {
    o_LeaveFeedback.open("Feedback.txt", ios::app);
    if (!o_LeaveFeedback.is_open()) {
        cout << "������� � ������ �����" << endl;
        return;
    }

    system("cls");
    cout << "������ ��� ��'�: ";
    cin >> name;
    cout << "������ ������� ������ 1 - 5: ";
    cin >> stars;

    if (stars > 5) stars = 5;
    if (stars < 0) stars = 0;

    cout << "������� ���� ����� ������: ";
    cin >> coment;

    o_LeaveFeedback << setw(15) << left << name << " | ";
    o_LeaveFeedback << setw(14) << left;

    for (int i = 0; i < stars; ++i) o_LeaveFeedback << "*";
    o_LeaveFeedback << " | ";
    o_LeaveFeedback << coment << endl;

    o_LeaveFeedback.close();
}
