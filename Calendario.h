#ifndef CALENDARIO_H
#define CALENDARIO_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void mostrarCalendario() {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);                  
    timeinfo = localtime(&rawtime);  
    int mes = timeinfo->tm_mon + 1;   
    int anio = timeinfo->tm_year + 1900; 
    string months[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Año bisiesto
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        days_in_month[1] = 29;
        
        switch (mes){
        case 1:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
        case 2:
            cout << "Calendario del mes: Febrero " << anio << endl;
            break;
            case 3:
            cout << "Calendario del mes: Marzo " << anio << endl;
            break;
            case 4:
            cout << "Calendario del mes: Abril " << anio << endl;
            break;
            case 5:
            cout << "Calendario del mes: Mayo " << anio << endl;
            break;
            case 6:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 7:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 8:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 9:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 10:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 11:
            cout << "Calendario del mes: Enero " << anio << endl;
            break;
            case 12:
            cout << "Calendario del mes: Enero " << anio << endl;
        default:
            cout << "Mes no valido" << endl;
            break;
        }


        
        for (int month = 0; month < 12; month++) {
        cout << "\nCalendario " << months[month] << " " << year << "\n";
        cout << " D  L  M  MI  J  V  S\n";
        for (int i = 0; i < day_of_week; i++) cout << "   ";
        for (int day = 1; day <= days_in_month[month]; day++) {
            cout << (day < 10 ? "  " : " ") << day;
            if ((day_of_week + day) % 7 == 0) cout << "\n";
        }
        if ((day_of_week + days_in_month[month]) % 7 != 0) cout << "\n";
        day_of_week = (day_of_week + days_in_month[month]) % 7;
    }
}
#endif