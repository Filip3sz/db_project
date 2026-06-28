//
// Created by Filip Bocian on 14/01/2026.
//

#ifndef DB_PROJECT_STAFF_UI_H
#define DB_PROJECT_STAFF_UI_H
#include "menu.h"

struct Pracownik {
    Logowanie log;

    Pracownik() {
        log.login = "root";
        log.haslo = "12345";
    }
};

extern Pracownik p;

int szukaj(string pesel);
void wygenerujkonto();
void zarejestruj();
void podajDane();
void listaPacjentow();
void usunPacjenta();
void umowienieWizyty();
void usunWizyte();
void historiaR();

#endif //DB_PROJECT_STAFF_UI_H