#include "Producto.h"
using namespace std;

Producto::Producto() : codigo(""), nombre(""), precio(0.0), cantidad(0) {}

Producto::Producto(string c, string n, float p, int cant)
    : codigo(c), nombre(n), precio(p), cantidad(cant) {}

Producto::~Producto() {}

string Producto::getCodigo() const { return codigo; }
string Producto::getNombre() const { return nombre; }
float Producto::getPrecio() const { return precio; }
int Producto::getCantidad() const { return cantidad; }

void Producto::setCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
}

void Producto::mostrarInfo() const {
    cout << "Codigo: " << codigo
         << " | Nombre: " << nombre
         << " | Precio: $" << precio
         << " | Cantidad: " << cantidad << endl;
}

