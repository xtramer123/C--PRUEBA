#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig = NULL;
    nodo *ant = NULL;
} *lista = NULL, *ultimo = NULL;

void crear(nodo *&, nodo *&, int);
void crear(nodo *&lista, nodo *&ultimo, int n)
{
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    if (lista == NULL) // Si la lista esta vacia
    {
        lista = nuevo;
        lista->ant = ultimo;
        ultimo = lista;
    }
    else
    {
        crear(lista->sig, ultimo, n);
    }
}

void mostrar(nodo *);
void mostrar(nodo *ultimo)
{
    nodo *actual = ultimo;
    if (actual != NULL)
    {
        cout << actual->dato << " <- ";
        mostrar(actual->ant);
    }
}

int main()
{
    int num;
    short dec;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Agregar un numero a la lista." << endl;
        cout << "2. Mostrar los numeros en la lista." << endl;
        cin >> dec;
        switch (dec)
        {
        case 1:
            cout << "Ingrese el dato que desea agregar:" << endl;
            cin >> num;
            crear(lista, ultimo, num);
            break;
        case 2:
            mostrar(ultimo);
            cout << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida." << endl;
            system("pause");
        }
        system("cls");
    } while (dec != 3);
}
