#include<iostream>
#include<string.h>
using namespace std;

struct Doctor {
    int id;
    string nombre;
    string especialidad;
};
struct Cita {
    int id;
    string paciente;
    string fecha;
    string hora;
    int doctorId;
};



void Menu(){
    int opcion;
     cout << "Seleccione una opción: ";
        cin >> opcion;
    do {
 switch(opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
        }
    } while(opcion != 3);


}

int main() {
    cout<< "HOSPITAL DEL Jonmar Vallejo/Jomaro Vallejo" << endl;
    
    return 0;
}