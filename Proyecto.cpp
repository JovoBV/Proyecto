#include <iostream>
#include <string>
#include <fstream>
#include "Login.h"
#include "Menu.h"
#include "Split.h"
using namespace std;

struct Doctor {
    string nombre;
    string especialidad;
};
struct Usuario {
    string cedula;
    string nombre;
    string apellido;
};


 void lee(Usuario* leidos) {
    ifstream leer("misdatos.txt");
    string datorecu;
    int pos = 0;
    string resultado[3];

    while (getline(leer, datorecu)) {
        cout << datorecu << endl;
        Split(datorecu, ' ', resultado);
        leidos[pos].cedula = resultado[0];
        leidos[pos].nombre = resultado[1];
        leidos[pos].apellido = resultado[2];
        pos++;
    }
    leer.close();
}



int main() {
     cout << "          Hospital Jomaro Vallejo             " << endl;
     cout << "...............Bienvenido.................." << endl;
     cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    login();  // Llamada a la función de login
    cin.ignore();
    cin.get();



    return 0;
}

