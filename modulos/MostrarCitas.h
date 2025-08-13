#ifndef MOSTRAR_CITAS_H
#define MOSTRAR_CITAS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Datos.h"
#include "AgendarCita.h"

using namespace std;

void mostrarCitas(string cedula) {
  bool flag = false;
  char opc;
  int aux = 1;
  int totalCitas =  leerCita(nullptr);
  Cita *citasRegistradas = new Cita[totalCitas];
  leerCita(citasRegistradas);
  

  cout << "\nCitas agendadas para la cedula " << cedula << ":\n\n";

  for (int i = 0; i < totalCitas; i++) {
    if (citasRegistradas[i].cedula == cedula) {
      cout << aux << ". Fecha: " << citasRegistradas[i].dia << "/"
            << citasRegistradas[i].mes << "/" << citasRegistradas[i].anio
            << ", Hora: " << citasRegistradas[i].hora
            << ", Doctor: " << citasRegistradas[i].doctor << endl;
      flag = true;
      aux ++;
    } 
  }

  if (!flag) cout << "No hay citas agendadas para la cedula " << cedula << endl;
  return;
}

#endif