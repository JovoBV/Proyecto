#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Doctor {
    string nombre;
    string especialidad;
};
struct Cita {
    string paciente;
    string fecha;
    string hora;
};

void cargarDoctores(int *contador, Doctor *medicos) {
    ifstream archivoDoctores("Doctores.txt");
    while (getline(archivoDoctores, medicos[*contador].nombre, '|') &&
           getline(archivoDoctores, medicos[*contador].especialidad)) {
        (*contador)++;
    }
    archivoDoctores.close();
}
/*linea de codigo de prueba*/
int main() {
    Doctor doctores[100];
    int contador = 0;

    cout << "HOSPITAL DEL Jonmar Vallejo/Jomaro Vallejo" << endl;
    cargarDoctores(&contador, doctores);
    cout << "Doctores" << endl;

    for (int i = 0; i < contador; i++) {
        cout << doctores[i].nombre << " - " << doctores[i].especialidad << endl;
    }

    return 0;
}