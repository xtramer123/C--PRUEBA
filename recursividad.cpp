#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct nodo
{
    int dato;
    nodo *ptr;
} *lista = NULL;

void agregar(nodo *&, int);
void mostrar(nodo *);
void agregar(nodo *&lista, int n)
{
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    if (lista == NULL)
    {
        lista = nuevo;
        nuevo->ptr = NULL;
    }
    else
    {
        agregar(lista->ptr, n);
    }
}

void buscar(nodo *lista)
{
    nodo *actual = lista;
    if (actual != NULL)
    {
        cout << actual->dato << "-> ";
        buscar(actual->ptr);
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
            agregar(lista, num);
            break;
        case 2:
            buscar(lista);
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