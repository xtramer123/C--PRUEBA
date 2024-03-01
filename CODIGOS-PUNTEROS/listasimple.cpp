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

int main()
{
    int n;
    do
    {
        cout << ".:.MENU.:." << endl;
        cout << "1) Agregar" << endl;
        cout << "2) Visualizar" << endl;
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
        default:
            cout << "OPCION NO VALIDA" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (n != 3);
    return 0;
}
