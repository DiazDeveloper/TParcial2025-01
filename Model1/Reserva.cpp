#include "Reserva.h"
#include <iostream>
#include <fstream> 

using namespace std;
void crearReserva(NodoReserva*& reservas)
{
    int idReserva, idCliente;
    string fechaReserva;

    cout << "Ingrese el ID de la reserva: ";
    cin >> idReserva;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

    cout << "Ingrese la fecha y hora de la reserva: ";
    cin >> fechaReserva;

    NodoReserva* nuevaReserva = new NodoReserva();

    nuevaReserva->reserva.idReserva = idReserva;
    nuevaReserva->reserva.idCliente = idCliente;
    nuevaReserva->reserva.fechaReserva = fechaReserva;

    nuevaReserva->siguiente = reservas;


    reservas = nuevaReserva;

    // Exportamos la info al archivo de texto
    ofstream salida;
    salida.open("reservas.txt", ios::app);

    if (salida.is_open())
    {
        salida << "DATOS DE LA RESERVA:" << endl;
        salida << "ID Reserva: " << nuevaReserva->reserva.idReserva << endl;
        salida << "ID Cliente: " << nuevaReserva->reserva.idCliente << endl;
        salida << "Fecha: " << nuevaReserva->reserva.fechaReserva << endl;
        salida << "----------------------------" << endl;

        salida.close();
    }

    cout << "Reserva con ID " << idReserva << " registrada exitosamente." << endl;
}


void reporteReservas(NodoReserva* reservas)
{
    if (reservas == nullptr)
    {
        cout << "No hay ninguna reserva en la lista" << endl;
        return;
    }

    // Mostrar la reserva actual
    cout << "Reserva:" << endl;
    cout << "ID Cliente: " << reservas->reserva.idCliente << endl;
    cout << "ID Reserva: " << reservas->reserva.idReserva << endl;
    cout << "Fecha de la Reserva: " << reservas->reserva.fechaReserva << endl;

    // Verificamos si el siguiente nodo existe
    if (reservas->siguiente != nullptr)
    {
        cout << "  --------------------  " << endl;  // Separador entre reservas
    }

    // Llamada recursiva para procesar el siguiente nodo en la lista
    reporteReservas(reservas->siguiente);
}


void anularReserva(NodoReserva*& reservas)
{
    if (reservas == nullptr)
    {
        cout << endl << "La lista de reservas est� vac�a." << endl;
        return;
    }

    int idReserva;
    cout << endl << "Ingrese el ID de la reserva a anular: ";
    cin >> idReserva;

    // Primera parte: Si la reserva a anular est� en la cabeza de la lista
    if (reservas->reserva.idReserva == idReserva)
    {
        NodoReserva* temp = reservas;  // Creamos un nodo temporal
        reservas = reservas->siguiente;  // Movemos la cabeza de la lista al siguiente nodo
        delete temp;  // Eliminamos el nodo temporal
        cout << "Reserva con ID " << idReserva << " anulada." << endl;
        return;
    }

    // Segunda parte: Desenlazar la reserva a anular
    NodoReserva* actual = reservas;
    while (actual->siguiente != nullptr && actual->siguiente->reserva.idReserva != idReserva)
    {
        actual = actual->siguiente;
    }

    // Tercera parte: Si se encuentra la reserva, se elimina
    if (actual->siguiente != nullptr)
    {
        NodoReserva* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        cout << "Reserva con ID " << idReserva << " anulada." << endl;
    }
    else
    {
        cout << "Reserva con ID " << idReserva << " no encontrada en la lista." << endl;
    }
}

