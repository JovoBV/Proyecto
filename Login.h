#ifndef LOGIN_H  
#define LOGIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "Datos.h"  
#include "Split.h" // Asegúrate de incluir tu librería Split

using namespace std;

bool login(string *id) {
    string cedula;
    cout << "Cedula: ";
    cin >> cedula;

    ifstream archivo("Credenciales.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de credenciales." << endl;
        return false;
    }

    string linea, resultado[3];
    bool encontrado = false;
    string nombre, apellido;
    while (getline(archivo, linea)) {
        int partes = Split(linea, ',', resultado);
        if (partes == 3 && cedula == resultado[0]) {
            nombre = resultado[1];
            apellido = resultado[2];
            encontrado = true;
            break;
        }
    }
    archivo.close();

    if (encontrado) {
        cout << "Login exitoso" << endl;
        cout << "Bienvenido, " << nombre << " " << apellido << "." << endl;
        *id = cedula;
        return true;
    } else {
        cout << "Usuario no encontrado.Desea registrarse? (s/n): ";
        char opcion;
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            Usuario nuevo;
            nuevo.cedula = cedula;
            cout << "Ingrese su nombre: ";
            cin >> nuevo.nombre;
            cout << "Ingrese su apellido: ";
            cin >> nuevo.apellido;
            ofstream archivo_out("Credenciales.txt", ios::app);
            if (archivo_out) {
                archivo_out << nuevo.cedula << "," << nuevo.nombre << "," << nuevo.apellido << endl;
                archivo_out.close();
                cout << "Usuario registrado exitosamente. Puede iniciar sesion ahora." << endl;
                *id = nuevo.cedula;
                return true;
            } else {
                cout << "No se pudo abrir el archivo para registrar." << endl;
            }
        }
        return false;
    }
}

#endif
