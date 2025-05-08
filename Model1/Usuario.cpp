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

void mostrarUsuariosRecursiva(queue<Usuario>& copiaUsuarios) 
{
    // Caso base: si la copia de la cola está vacía, hemos terminado
    if (copiaUsuarios.empty()) {
        return;
    }

    // Obtener el primer usuario
    Usuario usuarioActual = copiaUsuarios.front();

    // Mostrar la información del usuario
    cout << "ID Usuario: " << usuarioActual.idUsuario << endl;
    cout << "Nombre Usuario: " << usuarioActual.nombre << endl;
    cout << "------------------" << endl;

    // Eliminar el usuario mostrado
    copiaUsuarios.pop();

    // Llamada recursiva para el siguiente usuario
    mostrarUsuariosRecursiva(copiaUsuarios);
}

// Función para mostrar todos los usuarios (con recursividad)
void mostrarUsuarios(queue<Usuario>& usuarios)
{
    if (usuarios.empty()) {
        cout << "No hay usuarios registrados." << endl;
        return;
    }

    cout << "Usuarios registrados:" << endl;

    // Crear una copia de la cola para no modificar la original
    queue<Usuario> copiaUsuarios = usuarios;

    // Llamamos a la función recursiva para mostrar los usuarios
    mostrarUsuariosRecursiva(copiaUsuarios);
}


void ordenarUsuarios(queue<Usuario>& usuarios)
{
    // Si la cola está vacía o tiene solo un elemento, no hace falta ordenar
    if (usuarios.empty() || usuarios.size() == 1) {
        return;
    }

    // Paso 1: Transferir los usuarios de la cola a un vector
    vector<Usuario> usuarioVec;
    while (!usuarios.empty()) {
        usuarioVec.push_back(usuarios.front());
        usuarios.pop();
    }

    // Paso 2: Ordenar el vector por ID de usuario usando el algoritmo de burbuja
    for (size_t i = 0; i < usuarioVec.size(); ++i) {
        for (size_t j = 0; j < usuarioVec.size() - 1 - i; ++j) {
            if (usuarioVec[j].idUsuario > usuarioVec[j + 1].idUsuario) {
                Usuario temp = usuarioVec[j];
                usuarioVec[j] = usuarioVec[j + 1];
                usuarioVec[j + 1] = temp;
            }
        }
    }

    // Paso 3: Volver a insertar los usuarios ordenados en la cola
    for (const Usuario& u : usuarioVec) {
        usuarios.push(u);
    }
}