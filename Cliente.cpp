#include "Cliente.h"
#include "Venta.h"
using namespace std;

Cliente::Cliente() : id(""), nombre(""), email("") {}
Cliente::Cliente(string id, string nombre, string email)
    : id(id), nombre(nombre), email(email) {}
Cliente::~Cliente() {}

string Cliente::getId() const { return id; }
string Cliente::getNombre() const { return nombre; }
string Cliente::getEmail() const { return email; }

void Cliente::agregarVenta(Venta* venta) {
    historialVentas.push_back(venta);
}

void Cliente::mostrarHistorial() const {
    cout << "\n--- Historial de ventas de " << nombre << " ---\n";
    if (historialVentas.empty()) {
        cout << "Sin ventas registradas.\n";
    } else {
        for (auto v : historialVentas) {
            v->mostrarVenta();
        }
    }
}
