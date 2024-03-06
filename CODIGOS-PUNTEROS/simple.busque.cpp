#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct nodo
{
    string nombre;
    string dni;
    short edad;
    nodo *sig;
} *inicio = NULL, *fin = NULL;

void agregar(nodo *&);
void mostrar(nodo *);
void buscar(nodo *);

void agregar(nodo *&inicio)
{
    nodo *nuevo = new nodo;
    nuevo->sig = NULL;
    cout << "Ingresa nombre: ";
    fflush(stdin);
    getline(cin, nuevo->nombre);
    cout << "Ingresa DNI: ";
    cin >> nuevo->dni;
    cout << "Ingresa edad: ";
    cin >> nuevo->edad;
    if (inicio == NULL)
    {
        inicio = nuevo;
        fin = nuevo;
    }
    else
    {
        fin->sig = nuevo;
        fin = nuevo;
    }
}

void mostrar(nodo *inicio)
{
    nodo *actual = inicio;
    while (actual != NULL)
    {
        cout << "PERSONA " << endl;
        cout << "Nombre: " << actual->nombre << endl;
        cout << "DNI: " << actual->dni << endl;
        cout << "Edad: " << actual->edad << endl;
        cout << endl;
        actual = actual->sig;
    }
}

void buscar(nodo *inicio)
{
    string dniBuscado;
    nodo *busco = inicio;
    mostrar(inicio);
    if (inicio != NULL)
    {
        cout << "Ingresa dni: ";
        cin >> dniBuscado;
        while (busco != NULL)
        {
            if (busco->dni == dniBuscado)
            {
                cout << "ENCONTRADO: " << endl;
                cout << "Nombre: " << busco->nombre << endl;
                cout << "DNI: " << busco->dni << endl;
                cout << "Edad: " << busco->edad << endl;
                break; // el break es muy importante
            }
            else
            {
                busco = busco->sig;
            }
        }
    }
}

main()
{
    // menu de opciones
    int resp;
    do
    {
        cout << "Menu Principal\n";
        cout << "\t1.Insertar usuario.\n";
        cout << "\t2.Mostrar usuario.\n";
        cout << "\t3.buscar usuario.\n";
        cout << "\t4.Salir.\n";
        cout << "\nIngrese una opcion: ";
        cin >> resp;
        switch (resp)
        {
        case 1:
            agregar(inicio);
            break;
        case 2:
            mostrar(inicio);
            system("Pause");
            break;
        case 3:
            buscar(inicio);
            system("Pause");
            break;
        default:
            cout << "Opcion no valida.";
            system("Pause");
        }
        system("cls");
    } while (resp != 4);
}
