
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

#endif
