#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <iostream>
#include "Producto.h"

class Cliente;

class Venta {
private:
    int idVenta;
    Cliente* cliente;
    std::vector<Producto*> productos;
    std::vector<int> cantidades;
    float total;
public:
    Venta();
    Venta(int id, Cliente* cliente);
    ~Venta();

    void agregarProducto(Producto* producto, int cantidad);
    float calcularTotal();
    void mostrarVenta() const;
};

#endif
