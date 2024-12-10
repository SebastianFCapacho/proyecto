#include <iostream>
#include <string>
using namespace std;

const int MAX_ESPACIOS = 10;       
const int TARIFA_POR_HORA = 5;      

struct Vehiculo {
    string placa;
    int horaEntrada;
};

Vehiculo parqueadero[MAX_ESPACIOS];
int numVehiculos = 0;               

void registrarVehiculo(bool entrada) {
    if (entrada) {
        if (numVehiculos >= MAX_ESPACIOS) {
            cout << "El parqueadero esta lleno.\n";
            return;
        }
        Vehiculo nuevo;
        cout << "Ingrese la placa: ";
        cin >> nuevo.placa;
        cout << "Ingrese la hora de entrada (0-23): ";
        cin >> nuevo.horaEntrada;
        if (nuevo.horaEntrada < 0 || nuevo.horaEntrada > 23) {
            cout << "Hora invalida.\n";
            return;
        }
        parqueadero[numVehiculos] = nuevo;
        numVehiculos++;
        cout << "Entrada registrada.\n";
    } else {
        string placa;
        int horaSalida;
        cout << "Ingrese la placa: ";
        cin >> placa;
        bool encontrado = false;
        for (int i = 0; i < numVehiculos; i++) {
            if (parqueadero[i].placa == placa) {
                encontrado = true;
                cout << "Ingrese la hora de salida (0-23): ";
                cin >> horaSalida;
                if (horaSalida < 0 || horaSalida > 23) {
                    cout << "Hora invalida.\n";
                    return;
                }

                int tiempo = (horaSalida >= parqueadero[i].horaEntrada) ? 
                             (horaSalida - parqueadero[i].horaEntrada) : 
                             (24 - parqueadero[i].horaEntrada + horaSalida);

                int tarifa = tiempo * TARIFA_POR_HORA;

                cout << "Tiempo estacionado: " << tiempo << " horas.\n";
                cout << "Total a pagar: " << tarifa << " unidades monetarias.\n";

                for (int j = i; j < numVehiculos - 1; j++) {
                    parqueadero[j] = parqueadero[j + 1];
                }
                numVehiculos--;
                break;
            }
        }
        if (!encontrado) {
            cout << "Vehiculo no encontrado.\n";
        }
    }
}

void consultarEstado() {
    if (numVehiculos == 0) {
        cout << "El parqueadero esta vacio.\n";
        return;
    }
    cout << "Vehiculos en el parqueadero:\n";
    for (int i = 0; i < numVehiculos; i++) {
        cout << "Placa: " << parqueadero[i].placa << ", Hora de entrada: " << parqueadero[i].horaEntrada << "\n";
    }
}

int main() {
    int opcion;
    do {
        cout << "\n=== SISTEMA DE PARQUEADERO ===\n";
        cout << "1. Registrar entrada\n2. Registrar salida\n3. Consultar estado\n4. Salir\n Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVehiculo(true);  
                break;
            case 2:
                registrarVehiculo(false); 
            case 3:
                consultarEstado();        
                break;
            case 4:
                cout << "Saliendo del sistema...\n";  
                break;
            default:
                cout << "Opcion invalida.\n";  
        }
    } while (opcion != 4);  

    return 0;
}

