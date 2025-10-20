#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include <utility>
#include "Producto.h"
#include "Cliente.h"
#include "Venta.h"

class Tienda {
private:
    std::string nombre;
    std::vector<Producto*> inventario;
    std::vector<Cliente*> clientes;
    std::vector<Venta*> ventas;
public:
    Tienda();
    Tienda(std::string nombre);
    ~Tienda();

    void registrarProducto(std::string c, std::string n, float p, int cant);
    void registrarCliente(std::string id, std::string nombre, std::string email);
    void registrarVenta(std::string idCliente, std::vector<std::pair<std::string,int>> productos);

    void mostrarInventario() const;
    void mostrarClientes() const;
    float calcularValorTotalInventario() const;
    void inicializarDatos();
};

#endif
