//
// Created by Filip Bocian on 14/01/2026.
//

#ifndef DB_PROJECT_MENU_H
#define DB_PROJECT_MENU_H
#include <string>

using namespace std;

struct Logowanie {
    string login;
    string haslo;
};

bool logowanieR();
int logowanieP();
void menu();

#endif //DB_PROJECT_MENU_H