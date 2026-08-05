#include <iostream>
#include "data.h"
#include "staff_ui.h"
#include "patient_ui.h"

using namespace std;

bool logowanieR() {
    string login, haslo;
    int bledneProby = 0;

    while (login != p.log.login) {
        cout << "Podaj login: ";
        cin >> login;
        cout << endl;

        if (login != p.log.login) {
            cout << "Nie znaleziono takiego uzytkownika. Sprobuj ponownie." << endl;
        }
    }
    while (bledneProby < 3) {
        cout << "Podaj haslo: ";
        cin >> haslo;
        cout << endl;
        if (haslo == p.log.haslo) {
            cout << "Zalogowano!" << endl;
            return true;
        } else {
            cout << "Bledne haslo." << endl;
            bledneProby++;
        }
    }
    cout << "Przekroczono maksymalna ilosc prob logowania." << endl;
    bledneProby = 0;
    return false;
}

int logowanieP() {
    string login, haslo;
    int bledneProby = 0;
    int id = -1;

    while (true) {
        cout << "Podaj login: ";
        cin >> login;
        cout << endl;

        for (int i = 0; i < pacjenci; i++) {
            if (login == pac[i].log.login) {
                id = i;
                break;
            }
        }

        if (id == -1) {
            cout << "Nie znaleziono takiego uzytkownika. Sprobuj ponownie." << endl;
        } else {
            break;
        }
    }

    while (bledneProby < 3) {
        cout << "Podaj haslo: ";
        cin >> haslo;
        cout << endl;

        if (haslo == pac[id].log.haslo) {
            cout << "Zalogowano!" << endl;
            return id;
        } else {
            cout << "Bledne haslo." << endl;
            bledneProby++;
        }
    }

    cout << "Przekroczono maksymalna ilosc prob logowania." << endl;
    bledneProby = 0;
    return -1;
}

void menu() {
    wczytaj();

    bool zalogowany = false;
    int getId = -1;
    char chL;
    string ch;

    while (true) {
        if (!zalogowany) {
            cout << "##### PRZYCHODNIA #####" << endl;
            cout << "Logowanie jako pracownik - R" << endl;
            cout << "Logowanie jako pacjent - P" << endl;

            cout << "Wybierz opcje: ";
            cin >> chL;

            if (chL == 'R') {
                if (logowanieR()) {
                    zalogowany = true;
                    cout << "Zalogowano jako pracownik." << endl;
                    cout << endl;
                    cout << "##### PRZYCHODNIA BAZA DANYCH #####" << endl;
                    cout << "rejestracjapacjenta - ZAREJESTRUJ PACJENTA" << endl;
                    cout << "podajdane - UZYSKANIE DANYCH PACJENTA" << endl;
                    cout << "listapacjentow - LISTA PACJENTOW" << endl;
                    cout << "usunpacjenta - USUN PACJENTA" << endl;
                    cout << "umowwizyte - UMOW WIZYTE" << endl;
                    cout << "usunwizyte - USUN WIZYTE" << endl;
                    cout << "historiawizyt - HISTORIA WIZYT PACJENTA" << endl;
                    cout << "wyloguj - WYLOGUJ Z KONTA" << endl;
                    cout << "exit - WYJSCIE" << endl;

                    while (zalogowany) {

                        cout << "Wybierz akcje: ";
                        cin >> ch;

                        if (ch == "rejestracjapacjenta") zarejestruj();
                        else if (ch == "podajdane") podajDane();
                        else if (ch == "listapacjentow") listaPacjentow();
                        else if (ch == "usunpacjenta") usunPacjenta();
                        else if (ch == "umowwizyte") umowienieWizyty();
                        else if (ch == "usunwizyte") usunWizyte();
                        else if (ch == "historiawizyt") historiaR();
                        else if (ch == "wyloguj") {
                            zalogowany = false;
                            cout << "Wylogowano pomyslnie." << endl;
                        }
                        else if (ch == "exit") {
                            zapis();
                            cout << "Koniec programu." << endl;
                            break;
                        } else {
                            cout << "Niepoprawna opcja!" << endl;
                        }
                    }
                }
            } else if (chL == 'P') {
                getId = logowanieP();
                if (getId != -1) {
                    zalogowany = true;
                    cout << "Zalogowano jako pacjent." << endl;
                    cout << endl;
                    cout << "odwolajwizyte - ODWOLANIE ZAPLANOWANEJ WIZYTY" << endl;
                    cout << "historiawizyt - HISTORIA WIZYT PACJENTA" << endl;
                    cout << "wyloguj - WYLOGUJ Z KONTA" << endl;
                    cout << "exit - WYJSCIE" << endl;

                    while (zalogowany) {

                        cout << "Wybierz akcje: ";
                        cin >> ch;

                        if (ch == "odwolajwizyte") odwolajWizyte(getId);
                        else if (ch == "historiawizyt") historiaP(getId);
                        else if (ch == "wyloguj") {
                            zalogowany = false;
                            getId = -1;
                            cout << "Wylogowano pomyslnie." << endl;
                        }
                        else if (ch == "exit") {
                            zapis();
                            cout << "Koniec programu." << endl;
                            break;
                        } else {
                            cout << "Niepoprawna opcja!" << endl;
                        }
                    }
                }
            }
        }
    }
}