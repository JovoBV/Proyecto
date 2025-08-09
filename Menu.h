#ifndef Menu_H
#define Menu_H
#include <iostream>
#include <string>
#include "AgendarCita.h"
using namespace std;
void menu(string id){
int opcion;
    do {
        cout << "--- Agenda de Citas Medicas ---" << endl;
        cout << "1. Agendar una cita" << endl;
        cout << "2. Ver cita agendada" << endl;
        cout << "3. Cancelar cita" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            agendarCita(id);
                break;
            case 2:
            // Ver cita agendada
                break;
            case 3:
            // Cancelar cita
                break;
            case 4:
            cout << "Saliendo del sistema..." << endl;
            cout << "Gracias por usar el sistema de citas medicas." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}
#endif 