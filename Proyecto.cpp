
#include <iostream>
#include <string>
#include "Login.h"
#include "Menu.h"
using namespace std;

int main() {
    cout << "          Hospital Jomaro Vallejo             " << endl;
    cout << "...............Bienvenido.................." << endl;
    cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    if (login()) {
        menu();
    }

    
    cin.ignore();
    cin.get();
    return 0;
}
