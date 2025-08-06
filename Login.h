#ifndef LOGIN_H  
#define LOGIN_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int login() {
    string MAX_CEDULA;
    bool login_exitoso = false;  // Para saber si el login fue exitoso

    // Ciclo repetitivo
    while (!login_exitoso) {
        cout << "Cedula: ";
        getline(cin, MAX_CEDULA);  // Leer la cédula ingresada por el usuario

        ifstream leer("Credenciales.txt");  // Abrir el archivo de credenciales
        if (!leer) {
            cout << "No se pudo abrir el archivo de credenciales." << endl;
            return 0;  // Indicar error si no se puede abrir el archivo
        }

        string datorecuperacion;
        // Leer cada línea del archivo
        while (getline(leer, datorecuperacion)) {
            // Comparar la cédula del archivo con la ingresada por el usuario
            if (MAX_CEDULA == datorecuperacion) {
                login_exitoso = true;  // Si encuentra el usuario, termina el ciclo
                break;
            }
        }

        leer.close();

        if (!login_exitoso) {
            cout << "Usuario no encontrado. Intente nuevamente." << endl;
            cout << "Verifique si la cedula ingresada es la correcta." << endl;
        }
    }

    cout << "Login exitoso!" << endl;
    return 1;  // Indicar éxito
}

#endif  