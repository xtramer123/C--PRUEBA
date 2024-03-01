#include <iostream>
#include <string.h>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct nodo
{
    short dato;
    nodo *apuntador;
};
nodo *lista = NULL;
nodo *aux;
void agregar();
void mostrar();
void agregar()
{
    short n;
    nodo *nuevo = new nodo();
    cout << "Ingresa el dato: ";
    cin >> n;
    nuevo->dato = n;
    if (lista == NULL)
    {
        lista = nuevo;
        nuevo->apuntador = NULL;
        aux = nuevo;
    }
    else
    {
        aux->apuntador = nuevo;
        nuevo->apuntador = NULL;
        aux = nuevo;
    }
}
void mostrar()
{
    nodo *actual = new nodo();
    actual = lista;
    while (actual != NULL)
    {
        cout << actual->dato << " -> ";
        actual = actual->apuntador;
    }
}
int main()
{
    char dec;
    do
    {
        fflush(stdin);
        agregar();
        cout << "Ingresar (y/n): ";
        cin >> dec;
    } while (dec == 'y' || dec == 'Y');
    mostrar();
    return 0;
}