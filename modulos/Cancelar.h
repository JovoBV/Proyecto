#ifndef cancelarCitas_h
#define cancelarCitas_h

#include <iostream>
#include <fstream>
#include <string>
#include "Datos.h"
#include "MostrarCitas.h"

using namespace std;

void cancelarCita(string id) {
    int citaNumero;
    ifstream archivo("C:\\Users\\Jovo\\Documents\\GitHub\\Proyecto\\archivos\\RegistroCitas.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de citas." << endl;
        return;
    }

    // Mostrar las citas del usuario antes de cancelar
    cout << "Citas agendadas para la cédula: " << id << endl;
    mostrarCitas(id);  // Mostrar todas las citas para la cédula

    // Solicitar el número de cita a cancelar
    do {
        cout << "Ingrese el número de la cita que desea cancelar: ";
        cin >> citaNumero;
        if (citaNumero <= 0) {
            cout << "Numero de cita invalido. Intente nuevamente." << endl;
        }
    } while (citaNumero <= 0);

    ofstream tempArchivo("Temporal.txt");
    string linea;
    bool encontrado = false;
    int contadorCita = 1;  // Contador para identificar la cita por número

    // Leer el archivo y copiar las citas que no coincidan con la seleccionada
    while (getline(archivo, linea)) {
        size_t pos = linea.rfind(',');  // Encuentra la última coma
        string cedula;
        if (pos != string::npos) {
            cedula = linea.substr(pos + 1);  // Extrae la cédula
        } else {
            cedula = "";
        }

        // Si la cédula es la correcta, verificamos si es la cita seleccionada
        if (cedula == id) {
            if (contadorCita == citaNumero) {
                encontrado = true;  // Cita encontrada
                cout << "Cancelando cita numero: " << citaNumero << endl;
            } else {
                tempArchivo << linea << endl;  // Copiar la cita si no es la seleccionada
            }
            contadorCita++;
        } else {
            tempArchivo << linea << endl;  // Copiar las citas que no corresponden a esta cédula
        }
    }

    archivo.close();
    tempArchivo.close();

    // Reemplazar el archivo original por el temporal
    remove("RegistroCitas.txt");
    rename("Temporal.txt", "RegistroCitas.txt");

    if (encontrado) {
        cout << "Cita cancelada exitosamente." << endl;
    } else {
        cout << "No se encontró una cita para la cédula: " << id << " con el número de cita " << citaNumero << endl;
    }
}

#endif


