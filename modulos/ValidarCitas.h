#ifndef ValidarCitas_h
#define ValidarCitas_h

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "AgendarCita.h"
#include "Datos.h"       
#include "Calendario.h" 

using namespace std;

bool validarCita(string id, Cita nuevaCita) {
    int cantidadCitas = leerCita(nullptr);
    Cita* citasAgendadas = new Cita[cantidadCitas];
    int citasLeidas = leerCita(citasAgendadas);

    bool conflicto = false;
    for (int i = 0; i < cantidadCitas; i++) {
        // Mismo doctor en la misma fecha y hora
        if (citasAgendadas[i].dia == nuevaCita.dia &&
            citasAgendadas[i].mes == nuevaCita.mes &&
            citasAgendadas[i].anio == nuevaCita.anio &&
            citasAgendadas[i].hora == nuevaCita.hora &&
            citasAgendadas[i].doctor == nuevaCita.doctor) {
            cout << "El doctor " << nuevaCita.doctor << " ya tiene una cita agendada en esa fecha y hora.\n" << endl;
            conflicto = true;
            break;
        }

        // Mismo usuario en la misma fecha y hora
        if (citasAgendadas[i].cedula == id &&
            citasAgendadas[i].dia == nuevaCita.dia &&
            citasAgendadas[i].mes == nuevaCita.mes &&
            citasAgendadas[i].anio == nuevaCita.anio &&
            citasAgendadas[i].hora == nuevaCita.hora) {
            cout << "Ya tienes una cita agendada con el doctor " << citasAgendadas[i].doctor << " en esa fecha y hora.\n" << endl;
            conflicto = true;
            break;
        }
    }

    delete[] citasAgendadas; // Liberar memoria
    return conflicto;
}

#endif