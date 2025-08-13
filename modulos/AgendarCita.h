#ifndef AGENDAR_CITA_H
#define AGENDAR_CITA_H
#include <iostream>
#include <string>
#include <fstream>
#include "agendarhorarios.h"
#include "Datos.h"
#include "ValidarCitas.h"

using namespace std;

// Función para agendar una cita médica
void agendarEspecialidad(Cita *nuevaCita) {

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
    
    horarios(opc, nuevaCita);
}

void agendarCita(string id) {
    Cita nuevaCita;
    char opc;
    agendarEspecialidad(&nuevaCita);
    if (!validarCita(id, nuevaCita)) {
        ofstream archivo("archivos/RegistroCitas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << nuevaCita.dia << "," << nuevaCita.mes << "," << nuevaCita.anio
                << "," << nuevaCita.hora
                << "," << nuevaCita.doctor 
                << "," << id << endl;
        archivo.close();
        cout << "Cita agendada exitosamente." << endl;
    } else {
        cout << "Error al abrir el archivo para guardar la cita." << endl;
    }
    } else {
        cout << "Agendamiento no disponible." << endl;
        do {
            cout << "Desea intentar agendar otra cita? (s/n): ";
            cin >> opc;
            if (opc != 's' && opc != 'n') {
                cout << "Opcion no valida. Intente de nuevo." << endl;
            }
        } while (opc != 's' && opc != 'n');
        if (opc == 's') {
            agendarCita(id);
        } else {
            cout << "Saliendo del sistema de citas." << endl;
            return;
        }
        
    }
    
    
    
}

#endif