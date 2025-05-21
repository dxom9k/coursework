#pragma once
#include "Human.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Visitor : public Human {
private:
    int stars;
    vector<char> song;
    int a;
    char b;

    ofstream BookedTable;
    ofstream o_LeaveFeedback;
    ifstream Hours;

    vector<int> tables{ 4, 9, 3, 13 };

    string name;
    string coment;
    string s_Hours;

public:
    Visitor(int age, double balance, double card_balance);

    void OrderSong();
    string GetWorkHours();
    void BookTable();
    void LeavFeedBack();
};
