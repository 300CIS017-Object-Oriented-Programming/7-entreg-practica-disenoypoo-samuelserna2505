```mermaid
classDiagram
    class Producto {
        -string codigo
        -string nombre
        -float precio
        -int cantidad
        +Producto()
        +Producto(string c, string n, float p, int cant)
        +~Producto()
        +string getCodigo()
        +string getNombre()
        +float getPrecio()
        +int getCantidad()
        +void setCantidad(int nuevaCantidad)
        +void mostrarInfo()
    }

    class Cliente {
        -string id
        -string nombre
        -string email
        -vector<Venta*> historialVentas
        +Cliente()
        +Cliente(string id, string nombre, string email)
        +~Cliente()
        +string getId()
        +string getNombre()
        +string getEmail()
        +void agregarVenta(Venta* venta)
        +void mostrarHistorial()
    }

    class Venta {
        -int idVenta
        -Cliente* cliente
        -vector<Producto*> productos
        -vector<int> cantidades
        -float total
        +Venta()
        +Venta(int id, Cliente* cliente)
        +~Venta()
        +void agregarProducto(Producto* producto, int cantidad)
        +float calcularTotal()
        +void mostrarVenta()
    }

    class Tienda {
        -string nombre
        -vector<Producto*> inventario
        -vector<Cliente*> clientes
        -vector<Venta*> ventas
        +Tienda()
        +Tienda(string nombre)
        +~Tienda()
        +void registrarProducto(string c, string n, float p, int cant)
        +void registrarCliente(string id, string nombre, string email)
        +void registrarVenta(string idCliente, vector<pair<string,int>> productos)
        +void mostrarInventario()
        +void mostrarClientes()
        +float calcularValorTotalInventario()
        +void inicializarDatos()
    }

    %% Relaciones
    Tienda -->  Producto 
    Tienda -->  Cliente 
    Tienda --> Venta 
    Venta -->  Cliente 
    Venta --> Producto 
    Cliente -->  Venta 
