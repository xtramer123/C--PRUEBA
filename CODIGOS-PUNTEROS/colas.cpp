#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
struct nodo
{
    int dato;
    nodo *sig;
} *cabeza = NULL, *cola = NULL;

void insertar(nodo *&, nodo *&, int);
void eliminar(nodo *&, nodo *&);
void mostrar(nodo *);

void insertar(nodo *&cabeza, nodo *&cola, int n)
{
    nodo *nueva_cola = new nodo;
    nueva_cola->dato = n;
    nueva_cola->sig = NULL;
    if (cabeza == NULL && cola == NULL)
    {
        cola = nueva_cola;
        cabeza = cola;
    }
    else
    {
        cabeza->sig = nueva_cola;
        cabeza = nueva_cola;
    }
}

void eliminar(nodo *&cabeza, nodo *&cola)
{
    nodo *eliminar = cola;
    if (cola == cabeza)
    {
        cola = NULL;
        cabeza = NULL;
        delete eliminar;
    }
    else
    {
        cola = cola->sig;
        delete eliminar;
    }
}

void mostrar(nodo *cola)
{
    if (cola != NULL)
    {
        cout << cola->dato << "->";
        mostrar(cola->sig);
    }
}

int main()
{
    // menu de opciones
    int resp;
    int num;
    do
    {
        cout << "Menu Principal\n";
        cout << "\t1.Insertar Datos.\n";
        cout << "\t2.Mostrar Datos.\n";
        cout << "\t3.Eliminar Datos.\n";
        cout << "\t4.Salir del Programa.\n";
        cout << "\nIngrese una opcion: ";
        cin >> resp;
        switch (resp)
        {
        case 1:
            cout << "Ingresa dato a agregar: ";
            cin >> num;
            insertar(cabeza, cola, num);
            break;
        case 2:
            cout << "Datos en la Cola:\n";
            mostrar(cola);
            system("Pause");
            break;
        case 3:
            eliminar(cabeza, cola);
            cout << "Dato de cabecera eliminado ";
            system("Pause");
            break;
        default:
            cout << "Opcion no valida.";
            system("Pause");
        }
        system("cls");
    } while (resp != 4);
}