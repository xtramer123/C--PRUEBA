#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct nodo
{
    int dato;
    nodo *der;
    nodo *izq;
} *arbol = NULL;

nodo *insertarArbol(int);
void mostrarArbol(nodo *);
void Agregar(nodo *&, int);

nodo *insertarArbol(int n)
{
    nodo *nuevo = new nodo;
    nuevo->dato = n;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

void Agregar(nodo *&arbol, int n)
{
    if (arbol == NULL)
    {
        nodo *nuevo = insertarArbol(n);
        arbol = nuevo;
    }
    else
    {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz)
            Agregar(arbol->izq, n);
        else
            Agregar(arbol->der, n);
    }
}

void mostrarArbol(nodo *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der, contador + 1);

        for (int i = 0; i < contador; i++)
        {
            cout << "    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, contador + 1);
    }
}

int main()
{
    char dec;
    int con = 0;
    do
    {
        cout << "Menu" << endl;
        cout << "(A)gregar un numero al Arbol" << endl;
        cout << "(M)ostrar el Arbol" << endl;
        cin >> dec;
        switch (dec)
        {
        case 'a':
            int num;
            cout << "Ingrese un Numero: ";
            cin >> num;
            Agregar(arbol, num);
            break;
        case 'm':
            system("cls");
            cout << endl;
            mostrarArbol(arbol, con);
            cout << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (dec != 'a' || dec != 'm');
    system("pause");
}
