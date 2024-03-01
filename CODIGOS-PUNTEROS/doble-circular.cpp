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
    nodo *ant;
};
nodo *inicio = NULL;
nodo *fin = NULL;

void create(int);
void read(nodo *);

void create(int n)
{
    nodo *nuevo = new nodo;
    nuevo->dato = n;
    if (inicio == NULL)
    {
        inicio = nuevo;
        fin = nuevo;
        inicio->sig = inicio;
        inicio->ant = fin;
    }
    else
    {
        fin->sig = nuevo;
        nuevo->ant = fin;
        fin = nuevo;
        fin->sig = inicio;
        inicio->ant = fin;
    }
}

void read(nodo *acutal)
{
    if (acutal != NULL)
    {
        if (acutal->ant == fin)
            cout << "(FIN) " << inicio->ant->dato << " <- ";
        // hacia atras
        cout << acutal->dato << " -> ";
        // hacia delante
        if (acutal->sig == inicio)
        {
            cout << acutal->sig->dato << " (INICIO) ";
            return;
        }
        else
            read(acutal->sig);
    }
}

main()
{
    // menu de opciones
    int resp;
    int num;
    do
    {
        cout << "Menu Principal\n";
        cout << "\t1.Insertar Datos.\n";
        cout << "\t2.Mostrar Datos.\n";
        cout << "\t3.Salir del Programa.\n";
        cout << "\nIngrese una opcion: ";
        cin >> resp;
        switch (resp)
        {
        case 1:
            cout << "Ingresa dato a agregar: ";
            cin >> num;
            create(num);
            break;
        case 2:
            cout << "Datos en la lista doble circular:\n";
            read(inicio);
            system("Pause");
            break;
        default:
            cout << "Opcion no valida.";
            system("Pause");
        }
        system("cls");
    } while (resp != 3);
}