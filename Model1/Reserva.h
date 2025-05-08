#pragma once
#ifndef Reserva_H
#define Reserva_H

#include <string>
using namespace std;

class Reserva
{
public:
    int idReserva;
    int idCliente;
    string fechaReserva;
};

struct NodoReserva
{
    Reserva reserva;
    NodoReserva* siguiente;
};

void crearReserva(NodoReserva*& reservas);
void reporteReservas(NodoReserva* reservas);
void anularReserva(NodoReserva*& reservas);
void ordenarReservas(NodoReserva* reservas);

#endif
