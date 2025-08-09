#ifndef AGENDAR_CITA_H
#define AGENDAR_CITA_H
#include <iostream>
#include <string>
#include "agendarhorarios.h"
using namespace std;

int agendarEspecialidad();  // Declaración previa
void horarios();  // Declaración previa
// Función para agendar una cita médica
int agendarEspecialidad() {
    int opc;
        do {
        cout<<"Seleccione La Especialidad "<<endl;
        cout << "--- Especialidades ---" << endl;
        cout << "1. Cardiologia" << endl;
        cout << "2. Pediatria" << endl;
        cout << "3. Neurologia" << endl;
        cout << "4. Dermatologia" << endl;
        cout << "5. Medicina General" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        if (opc < 1 || opc > 5) {
        cout << "Opcion no valida. Intente de nuevo." << endl;
        } 
        } while (opc < 1 || opc > 5);
     
     horarios(opc);

    return opc;
}
#endif