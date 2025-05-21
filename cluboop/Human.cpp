#include "Human.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Human::OrderDish() {
    
}

void Human::ReadFeedback() {
    Feedback.open("Feedback.txt", ios::in);
    if (!Feedback.is_open()) {
        cout << "Помилка у відкриті файлу!!!" << endl;
    }
    else {
        cout << setw(20) << left << "Ім'я відвідувача" << " | "
            << setw(15) << left << "К-сть зірочок" << " | "
            << "Короткий відгук" << endl;
        while (getline(Feedback, Feedbacks)) {
            cout << Feedbacks << endl;
        }
        Feedback.close();
    }
}

double Human::GetCardBalance() {
    return this->card_balance;
}

void Human::SetBalance(double balance) {
    this->balance = balance;
}

void Human::SetCardBalance(double card_balance) {
    this->card_balance = card_balance;
}

double Human::GetBalance() {
    return this->balance;
}

void Human::SetWiFiPASS() {
    Pass.open("WiFiPassword.txt");
    if (Pass.is_open()) {
        getline(Pass, WiFiPassword);
        Pass.close();
    }
}

string Human::GetWiFiPassword() {
    WiFi.open("WiFiPassword.txt");
    if (WiFi.is_open()) {
        getline(WiFi, WiFiPassword);
        WiFi.close();
        return WiFiPassword;
    }
    else {
        return "!!!ERROR!!!";
    }
}

Human::~Human() {
    if (Pass.is_open()) Pass.close();
    if (Feedback.is_open()) Feedback.close();
    if (WiFi.is_open()) WiFi.close();
}
