<h1>DB_PROJECT - MEDICAL CLINIC DATABASE</h1>
<p>
  A <b>C++</b> programming project from the 1st semester at <b>PJATK</b>, awarded with a top grade <b>5.0 / A</b>.
</p>

<h2>Overview</h2>
<p>
  The database manages patient information and their scheduled appointments.<br>
  Data is stored in a simple <code>.txt</code> file <i>(I am aware this is not an ideal production setup and a SQL database like MySQL would be preferred, but the scope required a basic C++ implementation)</i>.<br>
  Patients get account access to manage their appointments.<br>
  Registration requires: <b>First Name, Last Name</b>, and <b>PESEL (ID number)</b>.<br>
  Logins and passwords are generated automatically by the system.
</p>

<h2>Features</h2>
<table>
  <tr>
    <td><b>Staff Features</b></td>
    <td><b>Patient Features</b></td>
  </tr>
  <tr>
    <td>
      • Creating and deleting patient accounts,<br>
      • Scheduling and canceling appointments,<br>
      • Viewing scheduled appointments for a specific patient,<br>
      • Searching for patients by PESEL number.
    </td>
    <td>
      • Viewing upcoming scheduled appointments,<br>
      • Canceling appointments independently.
    </td>
  </tr>
</table>

<h2>Installation & Configuration</h2>
<p>
  Compile the project using any C++ compiler supporting C++11 or higher (e.g., <code>g++ main.cpp -o db_project</code>) or build via CMake. Ensure the output executable resides in the same directory as the target data files.
</p>

<hr>

<h1>DB_PROJECT - BAZA DANYCH PRZYCHODNI LEKARSKIEJ</h1>
<p>
  Projekt z przedmiotu <b>Programowanie w C++</b> z pierwszego semestru na uczelni <b>PJATK</b>, zwieńczony oceną <b>5.0</b>.
</p>

<h2>Praktyczne zastosowanie</h2>
<p>
  Baza służy do przechowywania danych pacjentów oraz ich zaplanowanych wizyt.<br>
  Dane są zapisywane w pliku tekstowym <code>.txt</code> <i>(jestem świadomy, że nie jest to najbardziej praktyczne rozwiązanie i docelowo należałoby użyć bazy np. MySQL, jednak założeniem był prosty projekt w C++)</i>.<br>
  Pacjent ma zakładane konto, na które może się zalogować, aby np. odwołać wizytę.<br>
  Do założenia konta wymagane są: <b>Imię, Nazwisko</b> oraz <b>PESEL</b>.<br>
  System automatycznie generuje dla pacjenta login oraz hasło.
</p>

<h2>Funkcjonalności</h2>
<table>
  <tr>
    <td><b>Funkcje dla pracownika</b></td>
    <td><b>Funkcje dla pacjenta</b></td>
  </tr>
  <tr>
    <td>
      • Zakładanie oraz usuwanie konta pacjenta,<br>
      • Rejestracja nowej wizyty oraz jej odwoływanie,<br>
      • Przeglądanie zaplanowanych wizyt danego pacjenta,<br>
      • Wyszukiwanie pacjenta po numerze PESEL.
    </td>
    <td>
      • Przeglądanie własnych zaplanowanych wizyt,<br>
      • Możliwość samodzielnego odwołania wizyty.
    </td>
  </tr>
</table>

<h2>Instalacja i Konfiguracja</h2>
<p>
  Skompiluj projekt za pomocą dowolnego kompilatora C++ obsługującego standard C++11 lub wyższy (np. <code>g++ main.cpp -o db_project</code>) lub zbuduj go przy użyciu pliku CMake. Upewnij się, że plik wykonywalny znajduje się w tym samym katalogu co plik danych.
</p>