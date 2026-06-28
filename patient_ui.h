//
// Created by Filip Bocian on 14/01/2026.
//

#ifndef DB_PROJECT_PATIENT_UI_H
#define DB_PROJECT_PATIENT_UI_H
#include <string>
#include "menu.h"

const int MAX_PACJENTOW = 10;
const int MAX_WIZYT = 10;

using namespace std;

struct Wizyta {
    string data;
    string rozpoznanie;
};

struct Pacjent {
    Logowanie log;
    string pesel;
    string imie;
    string nazwisko;
    Wizyta wizyta[MAX_WIZYT];
    int wizyty = 0;
};

extern Pacjent pac[];
extern int pacjenci;

void historiaP(int id);
void odwolajWizyte(int id);

#endif //DB_PROJECT_PATIENT_UI_H