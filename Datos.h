#ifndef Datos_h
#define Datos_h
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

int leer(Usuario *leidos, int cantidad) {
    ifstream archivo("Credenciales.txt");
    if (!leer) {
            cout << "No se pudo abrir el archivo de credenciales." << endl;
            return 0;  // Indicar error si no se puede abrir el archivo
        }
    string datorecu;
    int pos = 0;
    string resultado[3];
    while (getline(archivo, datorecu) && pos < cantidad) {
        Split_h(datorecu, ' ', resultado);
            leidos[pos].cedula = resultado[0];
            leidos[pos].nombre = resultado[1];
            leidos[pos].apellido = resultado[2];
            pos++;
    }
    archivo.close();

    return pos;  // Retorna la cantidad de usuarios leídos
}
#endif