#include <iostream>
#include <fstream>
#include "data.h"
#include "patient_ui.h"

using namespace std;

void zapis() {
    ofstream plik("baza.txt");
    if (!plik.is_open()) {
        cout << "Blad zapisu!" << endl;
        return;
    }

    plik << pacjenci << endl;

    for (int i = 0; i < pacjenci; i++) {
        plik << pac[i].imie << endl;
        plik << pac[i].nazwisko << endl;
        plik << pac[i].pesel << endl;
        plik << pac[i].log.login << endl;
        plik << pac[i].log.haslo << endl;
        plik << pac[i].wizyty << endl;
        for (int j = 0; j < pac[i].wizyty; j++) {
            plik << pac[i].wizyta[j].data << endl;
            plik << pac[i].wizyta[j].rozpoznanie << endl;
        }
    }

    plik.close();
}

void wczytaj() {
    ifstream plik("baza.txt");
    if (!plik.is_open()) {
        cout << "Brak pliku." << endl;
        return;
    }

    plik >> pacjenci;
    plik.ignore();

    for (int i = 0; i < pacjenci; i++) {
        getline(plik, pac[i].imie);
        getline(plik, pac[i].nazwisko);
        getline(plik, pac[i].pesel);
        getline(plik, pac[i].log.login);
        getline(plik, pac[i].log.haslo);
        plik >> pac[i].wizyty;
        plik.ignore();

        for (int j = 0; j < pac[i].wizyty; j++) {
            getline(plik, pac[i].wizyta[j].data);
            getline(plik, pac[i].wizyta[j].rozpoznanie);
        }
    }

    plik.close();
}