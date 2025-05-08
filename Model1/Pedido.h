#pragma once
#ifndef Pedido_H
#define Pedido_H

#include <string>
using namespace std;

class Pedido
{
public:

	int idPedido;
	int idUsuario;
    float precioTotal;
	string fechaHora;  

};

struct NodoPedido
{
	Pedido pedido;
	NodoPedido* siguiente;
};

void crearPedido(NodoPedido*& pedidos);
void reportePedidos(NodoPedido* pedidos);
void anularPedido(NodoPedido*& pedidos);
void ordenarPedidos(NodoPedido* pedidos);


#endif