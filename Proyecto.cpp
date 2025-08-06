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


int main() {
     cout << "          Hospital Jomaro Vallejo             " << endl;
     cout << "...............Bienvenido.................." << endl;
     cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    login();  // Llamada a la función de login
    cin.ignore();
    cin.get();



    return 0;
}

