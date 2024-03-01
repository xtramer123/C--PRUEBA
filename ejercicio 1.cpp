#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

struct bebidas
{
    string nombre;
    bebidas *sig;
} *beb_ini = NULL, *beb_fin = NULL;

struct alcohol
{
    string nombre;
    alcohol *sig;
} *al_ini = NULL, *al_fin = NULL;

void agregarbeb()
{
    bebidas *nueva_bebida = new bebidas;
    fflush(stdin);
    cout << "Ingresa nombre  de la bebida: ";
    getline(cin, nueva_bebida->nombre);
    nueva_bebida->sig = NULL;
    if (beb_ini == NULL)
    {
        beb_ini = nueva_bebida;
        beb_fin = nueva_bebida;
    }
    else
    {
        beb_fin->sig = nueva_bebida;
        beb_fin = nueva_bebida;
    }
    cout << "\tDato ingresado correctamente" << endl;
}

void agregarAlco()
{
    alcohol *nuevo_al = new alcohol;
    fflush(stdin);
    cout << "Ingresa nombre  de la bebida alcoholica: ";
    getline(cin, nuevo_al->nombre);
    nuevo_al->sig = NULL;
    if (al_ini == NULL)
    {
        al_ini = nuevo_al;
        al_fin = nuevo_al;
    }
    else
    {
        al_fin->sig = nuevo_al;
        al_fin = nuevo_al;
    }
    cout << "\tDato ingresado correctamente" << endl;
}

void mostrar()
{
    bebidas *nonAlco = beb_ini;
    alcohol *alco = al_ini;
    if (nonAlco != NULL)
    {
        cout << "BEBIDAS NO ALCOHOLICAS" << endl;
        while (nonAlco != NULL)
        {
            cout << "Nombre: " << nonAlco->nombre << endl;
            nonAlco = nonAlco->sig;
        }
    }
    if (alco != NULL)
    {
        cout << "BEBIDAS  ALCOHOLICAS" << endl;
        while (alco != NULL)
        {
            cout << "Nombre: " << alco->nombre << endl;
            alco = alco->sig;
        }
    }
}

int main()
{
    int n;
    do
    {
        cout << ".:.MENU.:." << endl;
        cout << "1) Agregar Bebida" << endl;
        cout << "2) Agregar Alcoholica" << endl;
        cout << "3) Visualizar" << endl;
        cout << "Ingresar: ";
        cin >> n;
        switch (n)
        {
        case 1:
            agregarbeb();
            system("pause");
            break;
        case 2:
            agregarAlco();
            system("pause");
            break;
        case 3:
            mostrar();
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
