#include "Pedido.h"
#include <iostream>
#include <fstream> 

using namespace std;

void crearPedido(NodoPedido*& pedidos)
{

    int idPedido, idUsuario; 
    float precioTotal; 
    string fechaHora; 

    cout << "Ingrese el ID del pedido: "; 
    cin >> idPedido; 
    
    cout << "Ingrese el ID del usuario: ";
    cin >> idUsuario;

    cout << "Ingrese el precio total del pedido: ";
    cin >> precioTotal;
   
    cout << "Ingrese la fecha y hora del pedido: ";
    cin >> fechaHora;


    NodoPedido* nuevoPedido = new NodoPedido();

    nuevoPedido->pedido.idPedido = idPedido;
    nuevoPedido->pedido.idUsuario = idUsuario; 
    nuevoPedido->pedido.precioTotal = precioTotal;
    nuevoPedido->pedido.fechaHora = fechaHora;

    // El nuevo nodo apunta al primer pedido en la lista
    nuevoPedido->siguiente = pedidos;

    // Actualizamos la cabeza de la lista para que apunte al nuevo nodo
    pedidos = nuevoPedido;

    // exportamos info al txt

    ofstream salida; 
    salida.open("pedidos.txt", ios::app); // Abrir el archivo en modo append (agregar al final del archivo)

    if (salida.is_open())  
    {
        salida << "DATOS DEL PEDIDO:" << endl; 
        salida << "ID Pedido: " << nuevoPedido->pedido.idPedido << endl; 
        salida << "ID Usuario: " << nuevoPedido->pedido.idUsuario << endl; 
        salida << "Precio: " << nuevoPedido->pedido.precioTotal << endl; 
        salida << "Fecha: " << nuevoPedido->pedido.fechaHora << endl; 
        salida << "----------------------------" << endl; // Separador entre pedidos 

        salida.close(); // Cerrar el archivo después de escribir
    }


    cout << "Pedido con ID " << idPedido << " registrado exitosamente." << endl;

}

void reportePedidos(NodoPedido* pedidos)
{
   
    if (pedidos == nullptr) 
    {
        cout << "No hay ningun pedido en la lista" << endl;
        return;
    }

    cout << "Reporte de pedidos: " << endl;
    NodoPedido* actual = pedidos;
    while (actual != nullptr)
    {
        // Imprimir los detalles del pedido, cada uno en una línea nueva
        cout << "Pedido:" << endl;
        cout << "ID Usuario: " << actual->pedido.idUsuario << endl;
        cout << "ID Pedido: " << actual->pedido.idPedido << endl;
        cout << "Precio Total: " << actual->pedido.precioTotal << endl;
        cout << "Fecha y Hora: " << actual->pedido.fechaHora << endl;

        if (actual->siguiente != nullptr)
        {
            cout << "-----------------------------" << endl;  // Separador entre pedidos
        }
        actual = actual->siguiente;
    }

}

void anularPedido(NodoPedido*& pedidos)
{

    if (pedidos == nullptr)
    {
        cout << endl << "La lista de pedidos está vacía." << endl;
        return;
    }

    int idPedido;
    cout << endl << "Ingrese el ID del pedido a anular: ";
    cin >> idPedido;

    // Primera parte: Si el pedido a anular está en la cabeza de la lista
    if (pedidos->pedido.idPedido == idPedido)
    {
        NodoPedido* temp = pedidos;  // Creamos un nodo temporal
        pedidos = pedidos->siguiente;  // Movemos la cabeza de la lista al siguiente nodo
        delete temp;  // Eliminamos el nodo temporal
        cout << "Pedido con ID " << idPedido << " anulado." << endl;
        return;
    }

    // Segunda parte: Desenlazar el pedido a anular
    NodoPedido* actual = pedidos;
    while (actual->siguiente != nullptr && actual->siguiente->pedido.idPedido != idPedido)
    {
        actual = actual->siguiente;  
    }

    // Tercera parte: Si se encuentra el pedido, se elimina
    if (actual->siguiente != nullptr)
    {
        NodoPedido* temp = actual->siguiente;  
        actual->siguiente = actual->siguiente->siguiente; 
        delete temp;
        cout << "Pedido con ID " << idPedido << " anulado." << endl;
    }
    else
    {
        cout << "Pedido con ID " << idPedido << " no encontrado en la lista." << endl;
    }

}
