
#include <iostream>
#include <string>
#include "Login.h"
#include "Menu.h"
#include "Calendario.h" 
using namespace std;

int main() {
    cout << "          Hospital Jomaro Vallejo             " << endl;
    cout << "...............Bienvenido.................." << endl;
    cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    mostrarCalendario();
    if (login()) {
        menu();
    }

    
    cin.ignore();
    cin.get();
    return 0;
}
