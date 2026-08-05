#include <iostream>
#include <unistd.h>
#include "data.h"
#include "staff_ui.h"
#include "patient_ui.h"

Pracownik p;

int szukaj(string pesel) {
    if (pesel.length() != 11) {
        return -2;
    }
    for (int i = 0; i < pacjenci; i++) {
        if (pac[i].pesel == pesel) {
            return i;
        }
    }
    return -1;
}

void wygenerujKonto(int id) {
    string randomLogin = pac[id].imie + to_string(id + 1);
    string randomPass = "";
    const string znaki = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int idx = rand() % znaki.length();
        randomPass += znaki[idx];
    }
    pac[id].log.login = randomLogin;
    pac[id].log.haslo = randomPass;
    cout << "Wygenerowany login: " << pac[id].log.login << endl;
    cout << "Wygenerowane haslo: " << pac[id].log.haslo << endl;
}

void zarejestruj() {
    if (pacjenci >= MAX_PACJENTOW) {
        cout << "Baza pacjentow jest zapelniona! Usun pacjenta, by dodac nowego." << endl;
        return;
    }
    cout << "Imie: ";
    cin >> pac[pacjenci].imie;
    cout << "Nazwisko: ";
    cin >> pac[pacjenci].nazwisko;
    cout << "Pesel: ";
    cin >> pac[pacjenci].pesel;
    if (pac[pacjenci].pesel.length() != 11) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
        return;
    }
    int id = szukaj(pac[pacjenci].pesel);
    if (id != -1 && id != -2) {
        cout << "Jest juz zarejestrowany pacjent z takim peselem." << endl;
        return;
    }
    cout << "\nPacjent zostal zarejestrowany! Mozesz teraz umowic wizyte." << endl;
    cout << "\nTrwa generowanie konta dla pacjenta. Zaraz zostana wyswietlone jego dane do logowania." << endl;
    sleep(3);
    wygenerujKonto(pacjenci);
    sleep(1);
    pacjenci++;
}

void podajDane() {
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    cout << endl;
    int id = szukaj(pesel);
    if (id == -1) {
        cout << "Pacjent nie istnieje.";
    } else if (id == -2) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
    } else {
        cout << "Dane pacjenta o peselu " << pesel << ": " << pac[id].log.login << " " << pac[id].log.haslo << endl;
    }
}

void listaPacjentow() {
    for (int i = 0; i < pacjenci; i++) {
        cout << i + 1 << ". " << pac[i].imie << " " << pac[i].nazwisko << " " << pac[i].pesel << endl;
    }
}

void usunPacjenta() {
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    cout << endl;
    int id = szukaj(pesel);
    if (id == -1) {
        cout << "Pacjent nie istnieje.";
    } else if (id == -2) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
    } else {
        for (int i = id; i < pacjenci; i++) {
            pac[i] = pac[i + 1];
        }
        pacjenci--;
        cout << "Pacjent zostal usuniety." << endl;
    }
}

void umowienieWizyty() {
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    cout << endl;

    int id = szukaj(pesel);
    if (id == -1) {
        cout << "Pacjent nie istnieje.";
    } else if (id == -2) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
    } else if (pac[id].wizyty == MAX_WIZYT) {
        cout << "Ten pacjent ma juz maksymalna ilosc wizyt. Usun wizyte, by dodac nowa." << endl;
    } else {
        cout << "Podaj date: ";
        cin >> pac[id].wizyta[pac[id].wizyty].data;
        cout << "\nPodaj diagnoze: ";
        cin.ignore();
        getline(cin, pac[id].wizyta[pac[id].wizyty].rozpoznanie);
        cout << "Wizyta zostala umowiowa!" << endl;
        pac[id].wizyty++;
    }
}

void usunWizyte() {
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    cout << endl;

    int id = szukaj(pesel);
    if (id == -1) {
        cout << "Pacjent nie istnieje.";
    } else if (id == -2) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
    } else if (pac[id].wizyty == 0) {
        cout << "Ten pacjent nie ma zadnych zaplanowanych wizyt." << endl;
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

void historiaR() {
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    cout << endl;

    int id = szukaj(pesel);
    if (id == -1) {
        cout << "Pacjent nie istnieje.";
    } else if (id == -2) {
        cout << "Wprowadzono niepoprawny format peselu (poprawny = 11 cyfer)." << endl;
    } else if (pac[id].wizyty == 0) {
        cout << "Ten pacjent nie ma zadnych zaplanowanych wizyt." << endl;
    } else {
        cout << pac[id].imie << " " << pac[id].nazwisko << " " << pac[id].pesel << endl;
        for (int i = 0; i < pac[id].wizyty; i++) {
            cout << id + 1 << ". " << pac[id].wizyta[i].data << " " << pac[id].wizyta[i].rozpoznanie << endl;
        }
    }
}