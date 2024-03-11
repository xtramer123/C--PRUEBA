#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

int particion(vector<int> &arreglo, int inicio, int final)
{
    int pivote = arreglo[inicio];
    int i = inicio + 1;
    for (int j = i; j <= final; j++)
    {
        if (arreglo[j] < pivote)
        {
            swap(arreglo[i], arreglo[j]);
            i++;
        }
    }
    swap(arreglo[inicio], arreglo[i - 1]);
    return i - 1;
}

void ordenamiento(vector<int> &arreglo, int ini, int fin) // aqui le paso de parametro los indices
{
    if (ini < fin)
    {
        int pivote = particion(arreglo, ini, fin);
        ordenamiento(arreglo, ini, pivote - 1);
        ordenamiento(arreglo, pivote + 1, fin);
    }
}

int main()
{
    vector<int> arreglo = {4, 6, -4, 0};
    int fin = arreglo.size() - 1;
    for (int i = 0; i < fin + 1; i++)
    {
        cout << arreglo[i] << ' ';
    }
    cout << endl;
    // ordena el arreglo de menor a mayor
    ordenamiento(arreglo, 0, fin);
    for (int i = 0; i < fin + 1; i++)
    {
        cout << arreglo[i] << ' ';
    }
    return 0;
}