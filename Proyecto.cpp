
#include <iostream>
#include <string>
#include "Login.h"
using namespace std;

int main() {
    cout << "          Hospital Jomaro Vallejo             " << endl;
    cout << "...............Bienvenido.................." << endl;
    cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    login();  // Llamada a la función de login
    cin.ignore();
    cin.get();
    return 0;
}
