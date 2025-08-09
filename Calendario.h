#ifndef CALENDARIO_H
#define CALENDARIO_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void mostrarCalendario(int day, int *diasMes) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);                  
    timeinfo = localtime(&rawtime);
    string mesNombre;  
    int mes = timeinfo->tm_mon + 1;   // +1 porque tm_mon es 0-11
    int anio = timeinfo->tm_year + 1900; 
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Año bisiesto
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        days_in_month[1] = 29;
        
    switch (mes){
        case 1: mesNombre = "Enero"; break;
        case 2: mesNombre = "Febrero"; break;
        case 3: mesNombre = "Marzo"; break;
        case 4: mesNombre = "Abril"; break;
        case 5: mesNombre = "Mayo"; break;       
        case 6: mesNombre = "Junio"; break;
        case 7: mesNombre = "Julio"; break;
        case 8: mesNombre = "Agosto"; break;
        case 9: mesNombre = "Septiembre"; break;
        case 10: mesNombre = "Octubre"; break;
        case 11: mesNombre = "Noviembre"; break;
        case 12: mesNombre = "Diciembre"; break;
        default: mesNombre = "Mes no válido"; break;
    }

    // Obtener el día de la semana del primer día del mes
    struct tm timeCalendar = {0};
    timeCalendar.tm_year = anio - 1900;
    timeCalendar.tm_mon = mes - 1;
    timeCalendar.tm_mday = 1;
    mktime(&timeCalendar);
    int day_of_week = timeCalendar.tm_wday;

    cout << "\nCalendario " << mesNombre << " " << anio << "\n";
    cout << " D  L  M  X  J  V  S\n";  // Orden Domingo a Sábado

    // Espacios para alinear el primer día
    for (int i = 0; i < day_of_week; i++)
        cout << "   ";

    // Imprimir días
    for (int d = 1; d <= days_in_month[mes-1]; d++) {
        // Resaltar el día actual
        if (d == day) {
            cout << "[" << (d < 10 ? " " : "") << d << "]";
        } else {
            cout << (d < 10 ? " " : "") << d << " ";
        }
        
        if ((day_of_week + d - 1) % 7 == 6 || d == days_in_month[mes-1])
            cout << "\n";
    }

    *diasMes = days_in_month[mes-1];
}
#endif