#ifndef AGENDAR_CITA_H
#define AGENDAR_CITA_H
#include <iostream>
#include <string>
#include "agendarhorarios.h"
using namespace std;

int agendarEspecialidad();  // Declaración previa

int agendarEspecialidad() {
    int opc;
    cout<<"Seleccione La Especialidad "<<endl;
    do {
        cout << "--- Especialidades ---" << endl;
        cout << "1. Cardiología" << endl;
        cout << "2. Pediatría" << endl;
        cout << "3. Neurología" << endl;
        cout << "4. Dermatología" << endl;
        cout << "5. Medicina General" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
            horarios();
                break;
            case 2:
            horarios();
                break;
            case 3:
            horarios();
                break;
            case 4:
            horarios();
                break;
            case 5:
            horarios();
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opc != 4);
    return opc;
}
#endif