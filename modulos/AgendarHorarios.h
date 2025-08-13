#ifndef Agendarhorarios_h
#define Agendarhorarios_h

#include <iostream>
#include <ctime>
#include <string>
#include "AgendarCita.h"
#include "Datos.h"       
#include "Calendario.h" 

using namespace std;


void horarios(int casoEspecialidad, Cita *nuevaCita) {
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
    string horarios[] = {
        "09:00 AM", "10:00 AM", "11:00 AM", "12:00 PM",
        "02:00 PM", "03:00 PM", "04:00 PM"
    };

    mostrarCalendario(diaP, &diasMes);

    do {
        cout << "Seleccione el dia para agendar la cita:";
        cin >> dia;
        if (dia < 1 || dia > diasMes) cout << "Opcion no valida. Intente de nuevo." << endl;
        if (dia < diaP) cout << "No se puede agendar una cita en el pasado. Intente de nuevo." << endl;
    } while (dia < 1 || dia > diasMes || dia < diaP);
    
    const int MAX_DOCTORES = 10;
    Doctores medicos[MAX_DOCTORES];
    int total_Doctores = leerDoc(medicos);
    if (total_Doctores == 0) {
        cout << "Error al cargar los doctores." << endl;
    }
    
    int docDiscponible[2];
    string especialidades[] = {
        "Cardiologia", "Pediatria", "Neurologia", "Dermatologia", "MedicinaGeneral"
    };

    if (casoEspecialidad >= 1 && casoEspecialidad <= 5) {
        int aux = 0, aux2 = 0;
        string especialidadDoc = especialidades[casoEspecialidad - 1]; // Ajustamos el índice
        
        cout << "Doctores disponibles en " << especialidadDoc << ":" << endl;
        
        bool hayDoctoresDisponibles = false;
        
        for (int i = 0; i < total_Doctores; i++) {
            if (medicos[i].especialidad == especialidadDoc) {
                cout << aux2 + 1 << ". " << medicos[i].nombre << " " << medicos[i].apellido << endl;
                hayDoctoresDisponibles = true;
                docDiscponible[aux] = i; // Guardamos el índice del doctor disponible
                aux++;
                aux2++;
            }
        }
        
        if (!hayDoctoresDisponibles) {
            cout << "No hay doctores disponibles en esta especialidad." << endl;
        }
        } else {
        cout << "Especialidad no válida." << endl;
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
    for (int i = 0; i < 7; i++) {
        cout << i + 1 << ". " << horarios[i] << endl;
    }

    do {
    cout << "Seleccione un horario (1-7): ";
    cin >> opcion;
    if (opcion < 1 || opcion > 7) {
        cout << "Opcion no valida. Intente de nuevo." << endl;
    } } while (opcion < 1 || opcion > 7);
    
    cout << "Agendando cita con el Dr. "
        << medicos[docDiscponible[medico-1]].nombre << " "
        << medicos[docDiscponible[medico-1]].apellido
        << " el dia " << dia << "/" << mes << "/" << anio
        << " a las " << horarios[opcion-1] <<" ...\n"<< endl;

    nuevaCita->dia = dia;
    nuevaCita->mes = mes;
    nuevaCita->anio = anio;
    nuevaCita->hora = horarios[opcion-1];
    nuevaCita->doctor = medicos[docDiscponible[medico-1]].nombre + " " + medicos[docDiscponible[medico-1]].apellido;
}
#endif
