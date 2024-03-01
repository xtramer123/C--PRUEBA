#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;

int var;
struct nodo
{
    string *dato = new string[var];
};
short i = 0;

void agregar()
{
    i = 0;
    cout << "Ingresa nombre: ";
    getline(cin, nodo.dato[i]);
}

int main()
{
}