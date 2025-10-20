#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

class Producto {
private:
    std::string codigo;
    std::string nombre;
    float precio;
    int cantidad;
public:
    Producto();
    Producto(std::string c, std::string n, float p, int cant);
    ~Producto();

    std::string getCodigo() const;
    std::string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    void setCantidad(int nuevaCantidad);

    void mostrarInfo() const;
};

#endif



