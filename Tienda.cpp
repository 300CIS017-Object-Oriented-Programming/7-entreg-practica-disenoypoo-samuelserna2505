#include "Tienda.h"
#include <iostream>
using namespace std;

Tienda::Tienda() : nombre("Sin nombre") {}
Tienda::Tienda(string nombre) : nombre(nombre) {}

Tienda::~Tienda() {
    for (auto p : inventario) delete p;
    for (auto c : clientes) delete c;
    for (auto v : ventas) delete v;
}

void Tienda::registrarProducto(string c, string n, float p, int cant) {
    inventario.push_back(new Producto(c, n, p, cant));
    cout << "Producto registrado: " << n << endl;
}

void Tienda::registrarCliente(string id, string nombre, string email) {
    clientes.push_back(new Cliente(id, nombre, email));
    cout << "Cliente registrado: " << nombre << endl;
}

void Tienda::registrarVenta(string idCliente, vector<pair<string,int>> listaProductos) {
    Cliente* cliente = nullptr;
    for (auto c : clientes)
        if (c->getId() == idCliente)
            cliente = c;

    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Venta* venta = new Venta(ventas.size() + 1, cliente);

    for (auto par : listaProductos) {
        string cod = par.first;
        int cant = par.second;
        Producto* prod = nullptr;

        for (auto p : inventario)
            if (p->getCodigo() == cod)
                prod = p;

        if (!prod) {
            cout << "Producto con codigo " << cod << " no encontrado.\n";
            continue;
        }

        if (cant > prod->getCantidad()) {
            cout << "Stock insuficiente para " << prod->getNombre() << ".\n";
            continue;
        }

        venta->agregarProducto(prod, cant);
        prod->setCantidad(prod->getCantidad() - cant);
    }

    venta->calcularTotal();
    ventas.push_back(venta);
    cliente->agregarVenta(venta);
    cout << "Venta registrada con total: $" << venta->calcularTotal() << endl;
}

void Tienda::mostrarInventario() const {
    cout << "\n--- Inventario ---\n";
    for (auto p : inventario)
        p->mostrarInfo();
}

void Tienda::mostrarClientes() const {
    cout << "\n--- Clientes ---\n";
    for (auto c : clientes)
        cout << "ID: " << c->getId() << " | Nombre: " << c->getNombre() << " | Email: " << c->getEmail() << endl;
}

float Tienda::calcularValorTotalInventario() const {
    float total = 0;
    for (auto p : inventario)
        total += p->getPrecio() * p->getCantidad();
    return total;
}

void Tienda::inicializarDatos() {
    inventario.push_back(new Producto("P001", "Shampoo ecologico", 25000, 10));
    inventario.push_back(new Producto("P002", "Cepillo de bambu", 8000, 20));
    clientes.push_back(new Cliente("C001", "Juan Perez", "juan@email.com"));
    clientes.push_back(new Cliente("C002", "Maria Lopez", "maria@email.com"));
}
