
#include <iostream>
#include <string>
#include "Login.h"
#include "Menu.h"

using namespace std;

int main() {
    string identificacion;
    cout << "          Hospital Jomaro Vallejo             " << endl;
    cout << "...............Bienvenido.................." << endl;
    cout << "Ingrese su Numero de Cedula para Empezar" << endl;
    
    if (login(&identificacion)) {
        menu(identificacion);
    }

    
    cin.ignore();
    cin.get();
    return 0;
}
