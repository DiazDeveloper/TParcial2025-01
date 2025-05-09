#include "Comentarios.h"
#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

stack<Comentarios> pilaComentarios;
stack<Comentarios> pilaDeshacer;

void crearComentario(NodoComentarios*& comentarios)
{
    int idComentario, idUsuario;
    string textoComentario;

    cout << "Ingrese el ID del comentario: ";
    cin >> idComentario;
    cout << "Ingrese el ID del usuario: ";
    cin >> idUsuario;
    cout << "Ingrese el texto del comentario: ";
    cin >> textoComentario;

    // Crear un objeto Comentarios con los datos ingresados
    Comentarios nuevoComentario;
    nuevoComentario.idComenatario = idComentario;
    nuevoComentario.idUsuario = idUsuario;
    nuevoComentario.texto = textoComentario;

    // Guardar el comentario en la pila (para deshacer)
    pilaComentarios.push(nuevoComentario);

    // Crear un nuevo nodo para el comentario y agregarlo a la lista de comentarios
    NodoComentarios* nuevoNodo = new NodoComentarios();
    nuevoNodo->comentario = nuevoComentario;
    nuevoNodo->siguiente = comentarios;
    comentarios = nuevoNodo;

    // exportamos info al txt

    ofstream salida;
    salida.open("comentarios.txt", ios::app);

    if (salida.is_open())
    {
        // Escribir los datos del comentario en el archivo 
        salida << "DATOS DEL COMENTARIO:" << endl;
        salida << "ID Comentario: " << nuevoComentario.idComenatario << endl;
        salida << "ID Usuario: " << nuevoComentario.idUsuario << endl;
        salida << "Texto del Comentario: " << nuevoComentario.texto << endl;
        salida << "----------------------------" << endl;

        salida.close();
    }

    cout << "Comentario agregado exitosamente: " << textoComentario << endl;

    cin.get();   // get e ignore para que no se cierre automaticamente
    cin.ignore();
}


void mostrarComentarios(NodoComentarios* comentarios)
{
    if (comentarios == nullptr) {
        cout << "No hay comentarios" << endl;
        return;
    }

    // Mostrar el comentario actual
    cout << "ID Comentario: " << comentarios->comentario.idComenatario << endl;
    cout << "ID Usuario: " << comentarios->comentario.idUsuario << endl;
    cout << "Texto: " << comentarios->comentario.texto << endl;
    cout << " --------------------------- " << endl;

    // Llamada recursiva para el siguiente comentario
    mostrarComentarios(comentarios->siguiente);
}


void eliminarComentario(NodoComentarios*& comentarios)
{

    if (comentarios == nullptr) {
        cout << "No hay comentarios para eliminar" << endl;
        return;
    }

    // Tomamos el comentario a eliminar (el primero en la lista)
    NodoComentarios* temp = comentarios;
    Comentarios comentarioEliminado = comentarios->comentario;

    // Guardamos el comentario en la pila de deshacer
    pilaDeshacer.push(comentarioEliminado);

    // Ahora eliminamos el comentario de la lista
    comentarios = comentarios->siguiente;
    delete temp;  // Liberamos la memoria del nodo eliminado

    cout << "Comentario eliminado: " << comentarioEliminado.texto << endl;

}
