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
} *pila = NULL;

void insertarPila(nodo *&, int);
void mostrar(nodo *);
void eliminar(nodo *&);

void insertarPila(nodo *&pila, int n)
{
    nodo *nueva_pila = new nodo;
    nueva_pila->dato = n;
    nueva_pila->sig = pila;
    pila = nueva_pila;
}
void mostrar(nodo *pila)
{
    if (pila != NULL)
    {
        cout << "|" << endl;
        cout << "V" << endl;
        cout << pila->dato << endl;
        mostrar(pila->sig);
    }
}

void eliminar(nodo *&pila)
{
    nodo *eliminar = pila;
    if (pila != NULL)
    {
        pila = pila->sig;
        delete eliminar;
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
            insertarPila(pila, num);
            break;
        case 2:
            cout << "Datos en la Pila:\n";
            mostrar(pila);
            system("Pause");
            break;
        case 3:
            eliminar(pila);
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