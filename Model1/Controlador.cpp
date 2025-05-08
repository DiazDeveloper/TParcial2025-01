#include "Controlador.h"

void Controlador::mostrarMenu()
{
    cout << "=== MENU DE TRABAJO PARCIAL ===" << endl;
    cout << "1. Crear una reserva" << endl;
    cout << "2. Anular una reserva" << endl;
    cout << "3. Mostrar Reporte de reservas" << endl;
    cout << "4. Crear un comentario" << endl;
    cout << "5. Mostrar comentarios" << endl;
    cout << "6. Eliminar un comentario" << endl;
    cout << "7. Crear un usuario" << endl;
    cout << "8. Eliminar un usuario" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Controlador::IniciarProyecto()
{
	int opcion;
	NodoPedido* nodoP = nullptr;
    NodoReserva* nodoR = nullptr;
    NodoComentarios* nodoC = nullptr; 
    queue<Usuario> usuarios; 

	do
	{
		system("cls");
		mostrarMenu();
		cin >> opcion;
		cin.ignore();
        switch (opcion)
        {
        case 1:
            crearReserva(nodoR);
            break;
        case 2:
            anularReserva(nodoR); 
            break;
        case 3:
            reporteReservas(nodoR); 
            break;
        case 4:
            crearComentario(nodoC);  
            break;
        case 5:
            mostrarComentarios(nodoC); 
            break;
        case 6:
            eliminarComentario(nodoC);  
            break;
        case 7:
            registrarUsuarios(usuarios); 
            break;
        case 8:
            eliminarUsuario(usuarios);  
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }

	} while (opcion != 0);
}
