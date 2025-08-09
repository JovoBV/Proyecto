#ifndef Agendarhorarios_h
#define Agendarhorarios_h

#include <iostream>
#include <ctime>
#include <string>
#include "AgendarCita.h"  
#include "Datos.h"       
#include "Calendario.h" 

using namespace std;


void horarios(int casoEspecialidad) {
    int diasMes;
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);                  
    timeinfo = localtime(&rawtime);  
    int medico=0;
    int diaP = timeinfo->tm_mday;
    int dia;
    int mes = timeinfo->tm_mon + 1;   
    int anio = timeinfo->tm_year + 1900; 
    mostrarCalendario(diaP, &diasMes);
    do {
        cout << "Seleccione el dia para agendar la cita:";
        cin >> dia;
        if (dia < 1 || dia > diasMes) cout << "Opcion no valida. Intente de nuevo." << endl;
        if (dia < diaP) cout << "No se puede agendar una cita en el pasado. Intente de nuevo." << endl;
    } while (dia < 1 || dia > diasMes || dia < diaP);
    
    const int MAX_DOCTORES = 10;
    Doctores medicos[MAX_DOCTORES];
    int total_Doctores = leer1(medicos, MAX_DOCTORES);
    if (total_Doctores == 0) {
        cout << "Error al cargar los doctores." << endl;
    }
    int aux=1;
    int docDiscponible[2];
    for (int i = 0; i < total_Doctores; i++) {
        if (
            (casoEspecialidad == 1 && medicos[i].especialidad == "Cardiología") ||
            (casoEspecialidad == 2 && medicos[i].especialidad == "Pediatría") ||
            (casoEspecialidad == 3 && medicos[i].especialidad == "Neurología") ||
            (casoEspecialidad == 4 && medicos[i].especialidad == "Dermatología") ||
            (casoEspecialidad == 5 && medicos[i].especialidad == "MedicinaGeneral")
        ) {
            cout <<aux<<". "<<"Doctor disponible: " << medicos[i].nombre << " " << medicos[i].apellido << endl;
            aux++;
            for (int j = 0; j < 2; j++){
                docDiscponible[j] = i;
            }
    
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
    cout << "4. 12:00 AM" << endl;
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
    
    string horarios[] = {
        "09:00 AM", "10:00 AM", "11:00 AM", "12:00 PM",
        "02:00 PM", "03:00 PM", "04:00 PM"
    };

    cout << "Cita agendada con el Dr. "
        << medicos[docDiscponible[medico-2]].nombre << " "
        << medicos[docDiscponible[medico-2]].apellido
        << " el dia " << dia << "/" << mes << "/" << anio
        << " a las " << horarios[opcion-1] << endl;
}
#endif
