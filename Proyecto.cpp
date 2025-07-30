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


void agendarCita(Cita *citas, int *contador, Doctor *doctores) {
    // Agrega una cita al arreglo de citas
    cout << "Ingrese el nombre : ";
    cin >> citas[*contador].paciente;
    (*contador)++;
    int opc;
    cout<<"Seleccione La Especialidad "<<endl;
    do {
        cout << "--- Especialidades ---" << endl;
        cout << "1. Cardiología" << endl;
        cout << "2. Pediatría" << endl;
        cout << "3. Neurología" << endl;
        cout << "4. Dermatología" << endl;
        cout << "5. Medicina General" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:

                break;
            case 2:
 
                break;
            case 3:

                break;
            case 4:

                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opc != 4);
}





void cargarDoctores(int *contador, Doctor *medicos) {
    // Extrae los datos de los doctores desde un archivo
    // y los almacena en el arreglo de estructuras Doctor.
    ifstream archivoDoctores("Doctores.txt");
    getline(archivoDoctores, medicos[*contador].nombre);
        (*contador)++;
    archivoDoctores.close();
}

int main() {
    Cita citas[100];
    Doctor doctores[100];
    int contador = 0;
    cout << "HOSPITAL DEL JOMARO VALLEJO" << endl;
    cargarDoctores(&contador, doctores);

      int opcion;
    do {
        cout << "--- Agenda de Citas Medicas ---" << endl;
        cout << "1. Agendar una cita" << endl;
        cout << "2. Ver cita agendada" << endl;
        cout << "3. Cancelar cita" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            // Agendar una cita
            agendarCita(citas, &contador, doctores);
                break;
            case 2:
            // Ver cita agendada
                break;
            case 3:
            // Cancelar cita
                break;
            case 4:
            // Salir del programa
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}

