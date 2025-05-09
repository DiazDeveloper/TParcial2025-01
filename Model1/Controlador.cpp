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
    cout << "9. Mostrar usuarios" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void pausarPantalla() {
    cout << "\nPresione ENTER para continuar...";
    cin.get();
}
void Controlador::IniciarProyecto()
{
    int opcion;

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
            pausarPantalla();
            break;
        case 2:
            anularReserva(nodoR);
            pausarPantalla();
            break;
        case 3:
            reporteReservas(nodoR);
            pausarPantalla();
            break;
        case 4:
            crearComentario(nodoC);
            pausarPantalla();
            break;
        case 5:
            mostrarComentarios(nodoC);
            pausarPantalla();
            break;
        case 6:
            eliminarComentario(nodoC);
            pausarPantalla();
            break;
        case 7:
            registrarUsuarios(usuarios);
            pausarPantalla();
            break;
        case 8:
            eliminarUsuario(usuarios);
            pausarPantalla();
            break;
        case 9:
            mostrarUsuarios(usuarios);
            pausarPantalla();
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            pausarPantalla();
            break;
        }

    } while (opcion != 0);
}
