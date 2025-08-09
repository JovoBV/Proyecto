#ifndef DATOS_H
#define DATOS_H

#include <iostream>
#include <string>
#include <fstream>
#include "Split.h"

using namespace std;

struct Usuario {
    string cedula;
    string nombre;
    string apellido;
};
struct Doctores {
    string nombre;
    string apellido;
    string especialidad;
};

struct Cita {
    int dia;
    int mes;
    int anio;
    string hora;
    string doctor;
    string cedula;
};

int leer(Usuario* leidos, int cantidad) {
    ifstream archivo("Credenciales.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de credenciales." << endl;
        return 0;
    }

    string datorecu;
    int pos = 0;
    string resultado[3];

    while (getline(archivo, datorecu) && pos < cantidad) {
        int partes = Split(datorecu, ' ', resultado);
        if (partes >= 2) {
            leidos[pos].cedula = resultado[0];
            leidos[pos].nombre = resultado[1];
            leidos[pos].apellido = (partes >= 3) ? resultado[2] : "";
            pos++;
        }
    }

    archivo.close();
    return pos;
}

int leer1(Doctores* medicos, int cantidad) {
    ifstream texto("Doctores.txt");
    if (!texto) {
        cout << "No se pudo abrir el archivo de credenciales." << endl;
        return 0;
    }

    string datorecu1;
    int pos1 = 0;
    string resultado1[3];

    while (getline(texto, datorecu1) && pos1 < cantidad) {
        int partes = Split(datorecu1, ' ', resultado1);
        if (partes >= 2) {
            medicos[pos1].nombre = resultado1[0];
            medicos[pos1].apellido = resultado1[1];
            medicos[pos1].especialidad=resultado1[2];
            pos1++;
        }
    }

    texto.close();
    return pos1;
}

#endif
