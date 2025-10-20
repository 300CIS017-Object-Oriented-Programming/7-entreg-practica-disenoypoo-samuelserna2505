#include "Venta.h"
#include "Cliente.h"
using namespace std;

Venta::Venta() : idVenta(0), cliente(nullptr), total(0) {}
Venta::Venta(int id, Cliente* cliente) : idVenta(id), cliente(cliente), total(0) {}
Venta::~Venta() {}

void Venta::agregarProducto(Producto* producto, int cantidad) {
    productos.push_back(producto);
    cantidades.push_back(cantidad);
}

float Venta::calcularTotal() {
    total = 0;
    for (size_t i = 0; i < productos.size(); ++i)
        total += productos[i]->getPrecio() * cantidades[i];
    return total;
}

void Venta::mostrarVenta() const {
    cout << "\nVenta #" << idVenta << " - Cliente: " << cliente->getNombre() << endl;
    for (size_t i = 0; i < productos.size(); ++i) {
        cout << "Producto: " << productos[i]->getNombre()
             << " | Cantidad: " << cantidades[i]
             << " | Subtotal: $" << productos[i]->getPrecio() * cantidades[i] << endl;
    }
    cout << "Total venta: $" << total << endl;
}

