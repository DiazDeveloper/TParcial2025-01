#pragma once
#ifndef Comentarios_H
#define Comentarios_H

#include <string>
using namespace std;


class Comentarios
{
public:

	int idComenatario;
	int idUsuario;
	string texto;

};

struct NodoComentarios
{
	Comentarios comentario;
	NodoComentarios* siguiente;

};

void crearComentario(NodoComentarios*& comentarios);
void mostrarComentarios(NodoComentarios* comentarios);
void eliminarComentario(NodoComentarios*& comentarios);

#endif
