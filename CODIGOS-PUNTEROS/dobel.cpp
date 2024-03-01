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

void crear(nodo *&, int);
void crear(nodo *&lista, int n)
{
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    if (lista == NULL) // Si la lista esta vacia
    {
        lista = nuevo;
        ultimo = lista;
    }
    else
    {
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        ultimo = nuevo;
    }
}

void mostrar(nodo *);
void mostrar(nodo *lista)
{
    nodo *actual = lista;
    if (actual != NULL)
    {
        cout << actual->dato << " <- ";
        mostrar(actual->sig);
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
            crear(lista, num);
            break;
        case 2:
            mostrar(lista);
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
