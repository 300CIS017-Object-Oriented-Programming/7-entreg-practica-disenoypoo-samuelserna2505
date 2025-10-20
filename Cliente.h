#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <iostream>

class Venta; // Declaracion adelantada

class Cliente {
private:
    std::string id;
    std::string nombre;
    std::string email;
    std::vector<Venta*> historialVentas;
public:
    Cliente();
    Cliente(std::string id, std::string nombre, std::string email);
    ~Cliente();

    std::string getId() const;
    std::string getNombre() const;
    std::string getEmail() const;

    void agregarVenta(Venta* venta);
    void mostrarHistorial() const;
};

#endif

