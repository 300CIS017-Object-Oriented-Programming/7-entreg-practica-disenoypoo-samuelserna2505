#include <iostream>
#include "Tienda.h"

using namespace std;

int main() {
    Tienda tienda("EcoVida");
    tienda.inicializarDatos();

    int opcion;
    do {
        cout << "\n========= SISTEMA DE GESTION TIENDA ECOLOGICA =========\n";
        cout << "1. Registrar producto\n";
        cout << "2. Registrar cliente\n";
        cout << "3. Registrar venta\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Mostrar clientes\n";
        cout << "6. Calcular valor total del inventario\n";
        cout << "0. Salir\n";
        cout << "-------------------------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string c, n; float p; int cant;
                cout << "Codigo: "; cin >> c;
                cout << "Nombre: "; cin.ignore(); getline(cin, n);
                cout << "Precio: "; cin >> p;
                cout << "Cantidad: "; cin >> cant;
                tienda.registrarProducto(c, n, p, cant);
                break;
            }
            case 2: {
                string id, n, e;
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin.ignore(); getline(cin, n);
                cout << "Email: "; getline(cin, e);
                tienda.registrarCliente(id, n, e);
                break;
            }
            case 3: {
                string idCliente;
                cout << "ID del cliente: "; cin >> idCliente;
                vector<pair<string,int>> lista;
                char mas;
                do {
                    string cod; int cant;
                    cout << "Codigo producto: "; cin >> cod;
                    cout << "Cantidad: "; cin >> cant;
                    lista.push_back({cod, cant});
                    cout << "Agregar otro producto? (s/n): ";
                    cin >> mas;
                } while (mas == 's' || mas == 'S');
                tienda.registrarVenta(idCliente, lista);
                break;
            }
            case 4: tienda.mostrarInventario(); break;
            case 5: tienda.mostrarClientes(); break;
            case 6:
                cout << "Valor total del inventario: $" << tienda.calcularValorTotalInventario() << endl;
                break;
            case 0:
                cout << "Saliendo del sistema...\n"; break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
