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
    string especialidad;
    string cedula;
};

int leer(Usuario* leidos) {
    ifstream archivo("archivos/Credenciales.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de credenciales." << endl;
        return 0;
    }

    string datorecu;
    int pos = 0;
    string resultado[3];

    while (getline(archivo, datorecu)) {
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

int leerDoc(Doctores* medicos) {
    ifstream texto("archivos/Doctores.txt");
    if (!texto) {
        cout << "No se pudo abrir el archivo de credenciales." << endl;
        return 0;
    }

    string datorecu1;
    int pos1 = 0;
    string resultado1[3];

    while (getline(texto, datorecu1)) {
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

int leerCita(Cita* citas) {
    ifstream archivo("archivos/RegistroCitas.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de citas." << endl;
        return 0;
    }

    if (citas == nullptr) {
        string linea;
        int contador = 0;
        while (getline(archivo, linea)) contador++;
        archivo.close();
        return contador;
    }

    string datorecu;
    int pos = 0;
    string resultado[7];

    while (getline(archivo, datorecu)) {
        int partes = Split(datorecu, ',', resultado);
        if (partes >= 6) {
            citas[pos].dia = stoi(resultado[0]);
            citas[pos].mes = stoi(resultado[1]);
            citas[pos].anio = stoi(resultado[2]);
            citas[pos].hora = resultado[3];
            citas[pos].doctor = resultado[4];
            citas[pos].especialidad = resultado[5];
            citas[pos].cedula = resultado[6];  
            pos++;
        }
    }

    archivo.close();
    return pos;
}

#endif
