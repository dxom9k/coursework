#include "Admin.h"
#include "Dish.h"
#include "Visitor.h"
#include <Windows.h>
#include "Menu.h"
#include <locale>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void clearAndPause() {
    cout << endl << endl;
    system("pause");
    system("cls");
}

void showWelcomeMenu() {
    system("cls");
    cout << "+------------------------------------------+\n";
    cout << "|             ���� ������                 |\n";
    cout << "+------------------------------------------+\n";
    cout << "|  [1] ����� �� �����������             |\n";
    cout << "|  [2] ����� �� ����                     |\n";
    cout << "|  [0] ����� � ��������                    |\n";
    cout << "+------------------------------------------+\n";
    cout << "��� ����: ";
}

int main() {
    setlocale(LC_ALL, "ukr");

    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Admin admin;
    Menu menu;
    Visitor visitor(19, 500, 1000);
    double total = 0;

main_menu:
    showWelcomeMenu();
    int role; cin >> role;

    if (role == 1) {
        system("cls");
        if (!admin.Entrence()) {
            cout << "\n!!!������ ��²����!!!\n"; clearAndPause(); goto main_menu;
        }
    admin_menu:
        system("cls");
        cout << "1 - ������ ������ WiFi\n2 - ��������� �������\n3 - ������ ������ ������\n4 - �������� ��������\n5 - ������ ���� � ����\n6 - ������ ���� �� ����\n7 - �������� WiFi ������\n8 - ��������� ������\n0 - �����\n��� ����: ";
        int choice; cin >> choice;
        switch (choice) {
        case 1: admin.ChangeWiFiPassword(); break;
        case 2: cout << "\n������� ���������!\n"; break;
        case 3: admin.ChangeWorkHours(); break;
        case 4: admin.OrderProducts(); break;
        case 5: {
            int type;
            cout << "1 - ������, 2 - ����: ";
            cin >> type;
            if (type == 1) {
                cout << "1 - ��������\n2 - ������\n3 - �������\n4 - �������\n��� ����: ";
                cin >> type;
                menu.AddDish(type);
            }
            else {
                cout << "1 - ̳��\n2 - ������\n3 - ����\n4 - ������\n��� ����: ";
                cin >> type;
                menu.AddDirnk(type);
            }
            break;
        }
        case 6: admin.ChangeEntrancePrice(); break;
        case 7: cout << "WiFi: " << admin.GetWiFiPassword() << endl; break;
        case 8: admin.ReadFeedback(); break;
        case 0: goto main_menu;
        default: goto admin_menu;
        }
        clearAndPause();
        goto admin_menu;
    }
    else if (role == 2) {
    visitor_menu:
        system("cls");
        cout << "1 - �������� ����\n2 - �������� � ����\n3 - ���������� �������\n4 - ����������� ������ ������\n5 - �������� WiFi ������\n6 - ³�����\n7 - ����������� �������\n8 - �������� �������\n0 - �����\n��� ����: ";
        int choice; cin >> choice;
        int id, count, type;
        switch (choice) {
        case 1: visitor.OrderSong(); break;
        case 2:
            cout << "1 - ������\n2 - ����\n��� ����: ";
            cin >> type;
            if (type == 1) {
                cout << "1 - ��������\n2 - ������\n3 - �������\n4 - �������\n��� ����: ";
                cin >> type;
                menu.ShowMenu(type);
                cout << "ID: "; cin >> id;
                cout << "ʳ������: "; cin >> count;
                total += menu.OrderDishes(type, id, count);
            }
            else {
                cout << "1 - ̳��\n2 - ������\n3 - ����\n4 - ������\n��� ����: ";
                cin >> type;
                menu.ShowAlcohol(type);
                cout << "ID: "; cin >> id;
                cout << "ʳ������: "; cin >> count;
                total += menu.OrderAlcohol(type, id, count);
            }
            cout << "�����: " << total << " ���.\n";
            break;
        case 3: visitor.BookTable(); break;
        case 4: cout << "������: " << visitor.GetWorkHours() << endl; break;
        case 5: cout << "WiFi: " << visitor.GetWiFiPassword() << endl; break;
        case 6:
            cout << "1 - ������, 2 - ��������: ";
            cin >> type;
            (type == 1) ? visitor.ReadFeedback() : visitor.LeavFeedBack();
            break;
        case 7: menu.ShowBill(); cout << "����: " << total << " ���.\n"; break;
        case 8:
            cout << "1 - ������, 2 - �����: ";
            cin >> type;
            if (type == 1 && visitor.GetBalance() >= total) {
                visitor.SetBalance(visitor.GetBalance() - total);
                cout << "�������� �������\n"; total = 0;
            }
            else if (type == 2 && visitor.GetCardBalance() >= total) {
                visitor.SetCardBalance(visitor.GetCardBalance() - total);
                cout << "�������� �������\n"; total = 0;
            }
            else {
                cout << "����������� �����\n";
            }
            break;
        case 0: goto main_menu;
        default: goto visitor_menu;
        }
        clearAndPause();
        goto visitor_menu;
    }
    else if (role == 0) return 0;
    else goto main_menu;
}