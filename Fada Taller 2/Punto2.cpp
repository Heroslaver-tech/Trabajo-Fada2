/**
Sebastian Peñaranda
Luis Belalcazar
Punto 2 Taller 2 ADA I
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;
//Merge Sort
int a[50000];
void merge(int, int, int);
void merge_sort(int izquierda, int derecha) {
  int medio;
  if (izquierda < derecha) {
    medio = (izquierda + derecha) / 2;
    merge_sort(izquierda, medio);
    merge_sort(medio + 1, derecha);
    merge(izquierda, medio, derecha);
  }
}
void merge(int izquierda, int medio, int derecha) {
  int h, i, j, b[50], k;
  h = izquierda;
  i = izquierda;
  j = medio + 1;

  while ((h <= medio) && (j <= derecha)) {
    if (a[h] <= a[j]) {
      b[i] = a[h];
      h++;
    } else {
      b[i] = a[j];
      j++;
    }
    i++;
  }
  if (h > medio) {
    for (k = j; k <= derecha; k++) {
      b[i] = a[k];
      i++;
    }
  } else {
    for (k = h; k <= medio; k++) {
      b[i] = a[k];
      i++;
    }
  }
  for (k = izquierda; k <= derecha; k++) {
    a[k] = b[k];
  }
}
/* Recibir la entrada del problema
La entrada para este ejercicio sería : 
m: -> Número de apartamentos 
n: -> Número de aplicantes 
k:  -> Tolerancia en el precio de los aplicantes 
M: -> Precios de los apartamentos 
N: -> Dinero tentativo de los aplicantes

*/
int main(int argc, char *argv[]) {
  int apartamentos; // numero de apartamentos
  cout << "Escriba el numero de apartamentos: ";
  cin >> apartamentos;

  int aplicantes;
  cout << "Escriba la cantidad maxima de aplicantes a alquiler: ";
  cin >> aplicantes;

  int tolerancia;
  cout << "Escriba la tolerancia del precio de los aplicantes: ";
  cin >> tolerancia;

  int precios[apartamentos];
  for (int i = 0; i < apartamentos; i++) {
    cout << "Escriba los precios de cada apartamento, son un total de: "
         << apartamentos << ": ";
    cin >> a[i];
  }
  // Ordenamiento y guardado de el precio de los apartamentos
  merge_sort(0, apartamentos - 1);
  for (int i = 0; i < apartamentos; i++) {
    precios[i] = a[i];
  }
//Recibir el monto de dinero de los aplicantes
  int montos[aplicantes];
  for (int i = 0; i < aplicantes; i++) {
    cout << "Escriba los montos de dinero de cada aplicante, son un total de "
         << aplicantes << ": ";
    cin >> a[i];
  }
//Ordenar los montos por medio del merge sort
  merge_sort(0, aplicantes - 1);
  for (int i = 0; i < aplicantes; i++) {
    montos[i] = a[i];
  }
  // Funcion principal encargada de calcular cuantos apartamentos se pueden alquilar y fitrar los datos.
  int comprados = 0;
  for (int i = 0; i < apartamentos; i++) {
    for (int j = 0; j < aplicantes; j++) {
      if (((montos[j] - tolerancia) <= precios[i] &&
           (precios[i] <= (montos[j] + tolerancia))) ||
          (precios[i] == (montos[j]))) {
        comprados++;
        cout << "precio: " << i << endl;
        cout << "monto: " << j << endl;
        precios[i] = -1000;
        montos[j] = -100000;
        break;
      }
      if (montos[j + 1] - tolerancia > precios[i]) {
        break;
      }
    }
  }

  std::cout << comprados;
  return 0;
}