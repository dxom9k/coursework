#include "Admin.h"
#include <iostream>
#include <conio.h>  // ��� _getch()
#include <windows.h>  // ��� Sleep()
using namespace std;

bool Admin::Entrence() {
    cout << "������ ������: ";
    cin >> CheckPassword;
    return CheckPassword == password;
}

void Admin::ChangeWiFiPassword() {
    SetWiFiPASS();
    cout << "������ ������ ������: ";
    cin >> CheckPassword;

    ofstream WiFi("WiFiPassword.txt");

    if (CheckPassword == WiFiPassword) {
        cout << "������ ����� ������: ";
        cin >> NewWiFiPassword;
        system("cls");
        cout << "�������� ������: ";
        cin >> NewWiFiPassword1;

        if (NewWiFiPassword == NewWiFiPassword1) {
            WiFiPassword = NewWiFiPassword1;
            WiFi << NewWiFiPassword1;
        }
        else {
            cout << "�� ����� �� ������� �����!!!" << endl;
        }
    }
    else {
        cout << "!!!�� ����� ������������ ������!!!" << endl;
    }
    WiFi.close();
}

void Admin::ChangeWorkHours() {
    WorkHours.open("WorkHours.txt");

    if (WorkHours.is_open()) {
        cout << "������ ��� ������ ������: ";
        NewWorkHours.clear(); // ������� �������� ���
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
        cout << "�� ������� ������� ���� WorkHours.txt!" << endl;
    }

    WorkHours.close();
}

void Admin::ChangeEntrancePrice() {
    EntrancePriceFile.open("EntrencePrice.txt", ios::out);

    if (!EntrancePriceFile.is_open()) {
        cout << "������� � ������ �����!!!" << endl;
    }
    else {
        system("cls");
        cout << "������ ���� ���� �� ����: ";
        cin >> EntrancePrice;
        EntrancePriceFile << "ֳ�� �� ���� -- " << EntrancePrice << " ���.";
        EntrancePriceFile.close();
    }
}

void Admin::OrderProducts() {
    cout << "������ ����� ��������: ";
    cin >> Products;
    cout << "������ �������: ";
    cin >> number;
    system("cls");
    cout << "\n\n\n\t\t\t�������� ���������" << endl;
    Sleep(3000);
}

Admin::~Admin() {
    if (WiFi.is_open()) WiFi.close();
    if (WorkHours.is_open()) WorkHours.close();
    if (EntrancePriceFile.is_open()) EntrancePriceFile.close();
}
