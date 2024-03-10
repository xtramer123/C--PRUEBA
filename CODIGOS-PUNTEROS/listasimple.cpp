#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct nodo
{
    int dato;
    nodo *sgt;
};
// new = nuevo nodo
nodo *inicio = NULL;
nodo *final = NULL;

void agregar();
void mostrar();
void ordenar();
void agregar()
{
    nodo *nuevo = new nodo;
    cout << "Ingrese el dato: ";
    cin >> nuevo->dato;
    nuevo->sgt = NULL;
    if (inicio == NULL)
    {
        inicio = nuevo;
        final = nuevo;
    }
    else
    {
        final->sgt = nuevo;
        final = nuevo;
    }
}

void mostrar()
{
    nodo *actual = inicio;
    while (actual != NULL)
    {
        cout << actual->dato << "-> ";
        actual = actual->sgt;
    }
}

void ordenar()
{
    nodo *menor = inicio;
    while (menor != NULL)
    {
        nodo *sig = menor->sgt;
        while (sig != NULL)
        {
            if (menor->dato > sig->dato)
            {
                int copia = menor->dato;
                menor->dato = sig->dato;
                sig->dato = copia;
            }
            sig = sig->sgt;
        }
        menor = menor->sgt;
    }
    mostrar();
}

int main()
{
    int n;
    do
    {
        cout << ".:.MENU.:." << endl;
        cout << "1) Agregar" << endl;
        cout << "2) Visualizar" << endl;
        cout << "3) Ordenar" << endl;
        cout << "Ingresar: ";
        cin >> n;
        switch (n)
        {
        case 1:
            agregar();
            cout << "\tElemento correctamente agregado" << endl;
            system("pause");
            break;
        case 2:
            mostrar();
            system("pause");
            break;
        case 3:
            ordenar();
            system("pause");
            break;
        default:
            cout << "OPCION NO VALIDA" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (n != 4);
    return 0;
}
