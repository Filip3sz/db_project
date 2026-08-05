#include <iostream>
#include "patient_ui.h"

Pacjent pac[MAX_PACJENTOW];
int pacjenci = 0;

void historiaP(int id) {
    if (pac[id].wizyty == 0) {
        cout << "Nie posiadasz zadnych zaplanowanych wizyt." << endl;
    } else {
        cout << pac[id].imie << " " << pac[id].nazwisko << " " << pac[id].pesel << endl;
        for (int i = 0; i < pac[id].wizyty; i++) {
            cout << id + 1 << ". " << pac[id].wizyta[i].data << " " << pac[id].wizyta[i].rozpoznanie << endl;
        }
    }
}

void odwolajWizyte(int id) {
    if (pac[id].wizyty == 0) {
        cout << "Nie posiadasz zadnych zaplanowanych wizyt." << endl;
    } else {
        cout << pac[id].imie << " " << pac[id].nazwisko << " " << pac[id].pesel << endl;
        for (int i = 0; i < pac[id].wizyty; i++) {
            cout << id + 1 << ". " << pac[id].wizyta[i].data << " " << pac[id].wizyta[i].rozpoznanie << endl;
        }
        cout << "Ktora wizyte chcesz usunac (podaj numer): ";
        int n;
        cin >> n;
        n -= 1;
        for (int i = n; i < pac[id].wizyty; i++) {
            pac[id].wizyta[i] = pac[id].wizyta[i + 1];
        }
        pac[id].wizyty--;
        cout << "Wizyta zostala usunieta." << endl;
    }
}