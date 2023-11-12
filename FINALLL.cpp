#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Declaración de las clases Proveedor, Articulo, Compra y Venta
class Proveedor {
public:
    string nombre;
    string direccion;
};

class Articulo {
public:
    int id;
    string nombre;
    float precio; // El precio es ahora un valor decimal para incluir centavos.
    Proveedor proveedor;
};

class Compra {
public:
    Articulo articulo;
    int cantidad;
};

class Venta {
public:
    Articulo articulo;
    int cantidad;
};

// Función para guardar detalles de compras en un archivo
void guardarCompras(Compra compras[], int cantidadCompras) {
    ofstream archivoCompras("compras.txt"); // Abre un archivo para escribir las compras

    for (int i = 0; i < cantidadCompras; i++) {
        archivoCompras << "Id: " << compras[i].articulo.id << "\t";
        archivoCompras << "Nombre del Articulo: " << compras[i].articulo.nombre << " \t";
        archivoCompras << "Precio: " << compras[i].articulo.precio << "\n";
        archivoCompras << "Proveedor: " << compras[i].articulo.proveedor.nombre << "\t";
        archivoCompras << "Direccion del Proveedor: " << compras[i].articulo.proveedor.direccion << "\n";
        archivoCompras << "Cantidad: " << compras[i].cantidad << "\n";
        archivoCompras << "Total: " << compras[i].cantidad * compras[i].articulo.precio << "\n";
        archivoCompras << "------------------------------------------------\n";
    }

    archivoCompras.close(); // Cierra el archivo de compras
}

// Función para guardar detalles de ventas en un archivo
void guardarVentas(Venta ventas[], int cantidadVentas) {
    ofstream archivoVentas("ventas.txt"); // Abre un archivo para escribir las ventas

    for (int i = 0; i < cantidadVentas; i++) {
        archivoVentas << "Id: " << ventas[i].articulo.id << "\t";
        archivoVentas << "Nombre del Articulo: " << ventas[i].articulo.nombre << " \t";
        archivoVentas << "Precio: " << ventas[i].articulo.precio << "\n";
        archivoVentas << "Proveedor: " << ventas[i].articulo.proveedor.nombre << "\t";
        archivoVentas << "Direccion del Proveedor: " << ventas[i].articulo.proveedor.direccion << "\n";
        archivoVentas << "Cantidad: " << ventas[i].cantidad << "\n";
        archivoVentas << "Total: " << ventas[i].cantidad * ventas[i].articulo.precio << "\n";
        archivoVentas << "------------------------------------------------\n";
    }

    archivoVentas.close(); // Cierra el archivo de ventas
}

// Función para mostrar el contenido de un archivo
void mostrarContenidoArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << " para lectura." << endl;
    }
}

int main() {
    cout << "FACTURADOR.........." << endl;
    string nombreCliente;
    string direccionCliente;
    int cantidadArticulos;
    cout << "Ingrese su nombre \t";
    cin >> nombreCliente;
    cout << "Ingrese su direccion \t";
    cin >> direccionCliente;
    cout << "Ingrese la cantidad de articulos \t";
    cin >> cantidadArticulos;
    cout << "\n";

    // Declaración de un arreglo de objetos de la clase Articulo
    Articulo articulos[cantidadArticulos];

    // Ciclo para ingresar los datos de los artículos
    for (int i = 0; i < cantidadArticulos; i++) {
        articulos[i].id = (i + 1);
        cout << "Ingrese el nombre del articulo " << (i + 1) << " \t";
        cin >> articulos[i].nombre;
        cout << "Ingrese el precio \t\t";
        cin >> articulos[i].precio;

        // Agregar el 12% de IVA
        float iva = articulos[i].precio * 0.12; // Calcula el IVA (12% del precio)
        articulos[i].precio += iva; // Agrega el IVA al precio del artículo

        cout << "Ingrese el nombre del proveedor \t";
        cin >> articulos[i].proveedor.nombre;
        cout << "Ingrese la direccion del proveedor \t";
        cin >> articulos[i].proveedor.direccion;
    }

    int cantidadCompras, cantidadVentas;
    cout << "Ingrese la cantidad de compras \t";
    cin >> cantidadCompras;

    // Declaración de un arreglo de objetos de la clase Compra
    Compra compras[cantidadCompras];

    // Ciclo para ingresar los datos de las compras
    for (int i = 0; i < cantidadCompras; i++) {
        cout << "Ingrese el ID del articulo comprado \t";
        cin >> compras[i].articulo.id;
        cout << "Ingrese la cantidad comprada \t";
        cin >> compras[i].cantidad;
    }

    cout << "Ingrese la cantidad de ventas \t";
    cin >> cantidadVentas;

    // Declaración de un arreglo de objetos de la clase Venta
    Venta ventas[cantidadVentas];

    // Ciclo para ingresar los datos de las ventas
    for (int i = 0; i < cantidadVentas; i++) {
        cout << "Ingrese el ID del articulo vendido \t";
        cin >> ventas[i].articulo.id;
        cout << "Ingrese la cantidad vendida \t";
        cin >> ventas[i].cantidad;
    }

    // Llama a las funciones para guardar detalles de compras y ventas en archivos
    guardarCompras(compras, cantidadCompras);
    guardarVentas(ventas, cantidadVentas);

    cout << "Detalles de compras guardados en 'compras.txt'.\n";
    cout << "Detalles de ventas guardados en 'ventas.txt'.\n";

    int opcion;
    cout << "Menu:\n";
    cout << "1. Mostrar detalles de compras\n";
    cout << "2. Mostrar detalles de ventas\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            mostrarContenidoArchivo("compras.txt");
            break;
        case 2:
            mostrarContenidoArchivo("ventas.txt");
            break;
        case 3:
            break;
        default:
            cout << "Opción no valida\n";
    }

    return 0;
}