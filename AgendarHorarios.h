#ifndef Agendarhorarios_h
#define Agendarhorarios_h

#include <iostream>
#include <ctime>
#include <string>
#include "AgendarCita.h"  
#include "Datos.h"         
using namespace std;


void horarios(int casoEspecialidad) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);                  
    timeinfo = localtime(&rawtime);  
    int medico=0;
    int dia = 0;
    int mes = timeinfo->tm_mon + 1;   
    int anio = timeinfo->tm_year + 1900; 

    do {
        cout << "Seleccione el dia para agendar la cita\n";
        cout << "1. Lunes / 2. Martes / 3. Miercoles / 4. Jueves / 5. Viernes" << endl;
        cin >> dia;
        if (dia < 1 || dia > 5) {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (dia < 1 || dia > 5);

    const int MAX_DOCTORES = 10;
    Doctores medicos[MAX_DOCTORES];
    int total_Doctores = leer1(medicos, MAX_DOCTORES);
    if (total_Doctores == 0) {
        cout << "Error al cargar los doctores." << endl;
    }

    for (int i = 0; i < total_Doctores; i++) {
        if (
            (casoEspecialidad == 1 && medicos[i].especialidad == "Cardiología") ||
            (casoEspecialidad == 2 && medicos[i].especialidad == "Pediatría") ||
            (casoEspecialidad == 3 && medicos[i].especialidad == "Neurología") ||
            (casoEspecialidad == 4 && medicos[i].especialidad == "Dermatología") ||
            (casoEspecialidad == 5 && medicos[i].especialidad == "Medicina General")
        ) {
            cout <<i+1<<". "<<"Doctor disponible: " << medicos[i].nombre << " " << medicos[i].apellido << endl;
        }
    }
    do {
    cout << "Seleccione el doctor: ";
    cin >> medico;
        if (medico < 1 || medico > 2) {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        } 
    } while (medico < 1 || medico > 2);
    
    int opcion;
    cout << "Fecha : " << dia << "/" << mes << "/" << anio << endl;
    cout << "Horarios disponibles: " << endl;
    cout << "1. 09:00 AM" << endl;
    cout << "2. 10:00 AM" << endl;
    cout << "3. 11:00 AM" << endl;
    cout << "4. 12:00 PM" << endl;
    cout << "5. 02:00 PM" << endl;
    cout << "6. 03:00 PM" << endl;
    cout << "7. 04:00 PM" << endl;
    do
    {
    cout << "Seleccione un horario (1-7): ";
    cin >> opcion;
    if (opcion < 1 || opcion > 7) {
        cout << "Opcion no valida. Intente de nuevo." << endl;
    } } while (opcion < 1 || opcion > 7);
    cout << "Cita agendada con el Dr. " << medicos[medico - 1].nombre << " " << medicos[medico - 1].apellido 
         << " el dia " << dia << "/" << mes << "/" << anio 
         << " a las " << (opcion + 8) % 12 + 9 << ":00 " 
         << ((opcion + 8) / 12 == 0 ? "AM" : "PM") << endl;
}
#endif
