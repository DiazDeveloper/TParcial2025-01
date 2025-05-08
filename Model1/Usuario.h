#pragma once
#ifndef Usuario_H 
#define Usuario_H

#include <string>
#include <queue>

using namespace std;

class Usuario
{
public:

	int idUsuario;
	string nombre;

};

struct NodoUsuario 
{
	Usuario usuario;
	NodoUsuario* siguiente;
};
void registrarUsuarios(queue<Usuario>& usuarios); 
void eliminarUsuario(queue<Usuario>& usuarios); 
void mostrarUsuarios(queue<Usuario>& usuarios);
void ordenarUsuarios(queue<Usuario>& usuarios);

#endif
