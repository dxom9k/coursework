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
    cout << "|             Клуб Рутенія                 |\n";
    cout << "+------------------------------------------+\n";
    cout << "|  [1] Увійти як адміністратор             |\n";
    cout << "|  [2] Увійти як гість                     |\n";
    cout << "|  [0] Вийти з програми                    |\n";
    cout << "+------------------------------------------+\n";
    cout << "Ваш вибір: ";
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
            cout << "\n!!!ПАРОЛЬ НЕВІРНИЙ!!!\n"; clearAndPause(); goto main_menu;
        }
    admin_menu:
        system("cls");
        cout << "1 - Змінити пароль WiFi\n2 - Викликати охорону\n3 - Змінити години роботи\n4 - Замовити продукти\n5 - Внести зміни в меню\n6 - Змінити ціну за вхід\n7 - Показати WiFi пароль\n8 - Прочитати відгуки\n0 - Назад\nВаш вибір: ";
        int choice; cin >> choice;
        switch (choice) {
        case 1: admin.ChangeWiFiPassword(); break;
        case 2: cout << "\nОхорону викликано!\n"; break;
        case 3: admin.ChangeWorkHours(); break;
        case 4: admin.OrderProducts(); break;
        case 5: {
            int type;
            cout << "1 - Страви, 2 - Напої: ";
            cin >> type;
            if (type == 1) {
                cout << "1 - Авторські\n2 - Холодні\n3 - Десерти\n4 - Кальяни\nВаш вибір: ";
                cin >> type;
                menu.AddDish(type);
            }
            else {
                cout << "1 - Міцні\n2 - Середні\n3 - Пиво\n4 - Коктелі\nВаш вибір: ";
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
        cout << "1 - Замовити пісню\n2 - Замовити з меню\n3 - Бронювання столика\n4 - Переглянути години роботи\n5 - Показати WiFi пароль\n6 - Відгуки\n7 - Переглянути рахунок\n8 - Оплатити рахунок\n0 - Назад\nВаш вибір: ";
        int choice; cin >> choice;
        int id, count, type;
        switch (choice) {
        case 1: visitor.OrderSong(); break;
        case 2:
            cout << "1 - Страви\n2 - Напої\nВаш вибір: ";
            cin >> type;
            if (type == 1) {
                cout << "1 - Авторські\n2 - Холодні\n3 - Десерти\n4 - Кальяни\nВаш вибір: ";
                cin >> type;
                menu.ShowMenu(type);
                cout << "ID: "; cin >> id;
                cout << "Кількість: "; cin >> count;
                total += menu.OrderDishes(type, id, count);
            }
            else {
                cout << "1 - Міцні\n2 - Середні\n3 - Пиво\n4 - Коктелі\nВаш вибір: ";
                cin >> type;
                menu.ShowAlcohol(type);
                cout << "ID: "; cin >> id;
                cout << "Кількість: "; cin >> count;
                total += menu.OrderAlcohol(type, id, count);
            }
            cout << "Разом: " << total << " грн.\n";
            break;
        case 3: visitor.BookTable(); break;
        case 4: cout << "Графік: " << visitor.GetWorkHours() << endl; break;
        case 5: cout << "WiFi: " << visitor.GetWiFiPassword() << endl; break;
        case 6:
            cout << "1 - Читати, 2 - Залишити: ";
            cin >> type;
            (type == 1) ? visitor.ReadFeedback() : visitor.LeavFeedBack();
            break;
        case 7: menu.ShowBill(); cout << "Сума: " << total << " грн.\n"; break;
        case 8:
            cout << "1 - Готівка, 2 - Карта: ";
            cin >> type;
            if (type == 1 && visitor.GetBalance() >= total) {
                visitor.SetBalance(visitor.GetBalance() - total);
                cout << "Оплачено готівкою\n"; total = 0;
            }
            else if (type == 2 && visitor.GetCardBalance() >= total) {
                visitor.SetCardBalance(visitor.GetCardBalance() - total);
                cout << "Оплачено карткою\n"; total = 0;
            }
            else {
                cout << "Недостатньо коштів\n";
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