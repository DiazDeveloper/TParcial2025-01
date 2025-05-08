#include "Usuario.h"
#include <iostream>
#include <queue>

using namespace std;

void registrarUsuarios(queue<Usuario>& usuarios)
{

    Usuario nuevoUsuario;

    cout << "Ingrese el ID del usuario: "; 
    cin >> nuevoUsuario.idUsuario; 
    cin.ignore(); 
    cout << "Ingrese el nombre del usuario: "; 
    cin >> nuevoUsuario.nombre;

    usuarios.push(nuevoUsuario); 

    cout << "Usuario registrado exitosamente: " << nuevoUsuario.nombre << endl;

}

void eliminarUsuario(queue<Usuario>& usuarios)
{

    if (usuarios.empty()) 
    {
        cout << "No hay usuarios para eliminar." << endl;
        return;
    }

    // Sacamos al primer usuario de la cola
    Usuario usuarioEliminado = usuarios.front();
    usuarios.pop();  // Elimina al primer usuario de la cola

    cout << "Usuario eliminado: " << usuarioEliminado.nombre << endl;

}
