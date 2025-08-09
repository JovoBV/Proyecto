#ifndef AGENDAR_CITA_H
#define AGENDAR_CITA_H
#include <iostream>
#include <string>
#include <fstream>
#include "agendarhorarios.h"
using namespace std;

struct cita {
    int dia;
    int mes;
    int anio;
    string hora;
    string doctor;
};

// Función para agendar una cita médica
void agendarEspecialidad(cita *nuevaCita) {

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
    
    horarios(opc, &nuevaCita);
}

void agendarCita() {
    cita nuevaCita;

    agendarEspecialidad(&nuevaCita);
    ofstream archivo("citas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Cita agendada: "
                << nuevaCita.dia << "/" << nuevaCita.mes << "/" << nuevaCita.anio
                << " a las " << nuevaCita.hora
                << " con el Dr. " << nuevaCita.doctor << endl;
        archivo.close();
        cout << "Cita agendada exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo para guardar la cita." << endl;
    }
    
}

#endif