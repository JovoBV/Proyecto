
#ifndef LOGIN_H  
#define LOGIN_H

#include <iostream>
#include <string>
#include "Datos.h"  

using namespace std;

int login() {
    const int MAX_USUARIOS = 100;
    Usuario lista[MAX_USUARIOS];
    int total_usuarios = leer(lista, MAX_USUARIOS);

    if (total_usuarios == 0) {
        cout << "Error al cargar credenciales." << endl;
        return 0;
    }

    string MAX_CEDULA;
    bool login_exitoso = false;

    while (!login_exitoso) {
        cout << "Cedula: ";
        getline(cin, MAX_CEDULA);

        for (int i = 0; i < total_usuarios; i++) {
            if (lista[i].cedula == MAX_CEDULA) {
                cout << "Login exitoso" << endl;
                cout << "Bienvenido, " << lista[i].nombre << " " << lista[i].apellido << "." << endl;
                return 1;
            }
        }

        cout << "Usuario no encontrado. Intente nuevamente." << endl;
    }

    return 0;
}

#endif
