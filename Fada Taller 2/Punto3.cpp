/**
Sebastian Peñaranda
Luis Belalcazar
Punto 3 Taller 2 ADA I
*/

#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
/**
Recibir la entrada del ejercicio
Las entradas para esta solución:
- n: -> Número de grupos que entraron y salieron del restaurante.
- T: -> Arreglo conformado por partes que representa el momento en el que el i-ésimo grupo entró y salió del restaurante.

*/
  //Se recibe los datos en forma de una matriz que se llena por posicion para poder luego separar las entradas y salidas en dos arrays independientes.
  int grupos; // numero de grupos
  cout << "Escriba el numero de grupos que entraran: ";
  cin >> grupos;
  if (grupos == 1) {
    std::cout << 1;
    return 0;
  } else {
    int estadia[grupos][2];
    for (int i = 0; i < grupos; i++) {
      for (int j = 0; j < 2; j++) {
        cout << "Digite la entrada y despues la salida del grupo [" << i << "]["
             << j << "]: ";
        cin >> estadia[i][j];
      }
    }
   //Asignacion de los valores de entrada y salida alojados en la matriz a sus respectivos arrays
    int entradas[grupos];
    int salidas[grupos];
    for (int i = 0; i < grupos; i++) {
      entradas[i] = estadia[i][0];
      salidas[i] = estadia[i][1];
    }
    //Calculo de el menor y mayor tiempo de entrada para establecer un rango de tiempo
    int menorTiempoEntrada;
    int mayorTiempoSalida;
    for (int i = 0; i < grupos; i++) {
      if (i == 0) {
        menorTiempoEntrada = entradas[i];
        mayorTiempoSalida = salidas[i];
      } else if (entradas[i] < menorTiempoEntrada) {
        menorTiempoEntrada = entradas[i];
      } else if (salidas[i] > mayorTiempoSalida) {
        mayorTiempoSalida = salidas[i];
      } else {
      }
    }
    int rangoTiempo = mayorTiempoSalida - menorTiempoEntrada;
    int arrayTiempo[rangoTiempo];
    int mesas = 0;

    // inicializa el array arrayTiempo
    for (int x = 0; x <= rangoTiempo; x++) {
      arrayTiempo[x] = 0;
    }

   // Funcion principal encargada de contar y verificar cuantas mesas estan ocupadas en cada momento de tiempo en el rango establecido, inspirado en parte del counting sort.
    
    for (int tiempo = 0; tiempo <= rangoTiempo; tiempo++) {
      cout << "tiempo :" << tiempo + 2 << endl;
      for (int i = 0; i < grupos; i++) {
        if ((entradas[i] <= (tiempo + 2)) && ((tiempo + 2) < salidas[i])) {
          arrayTiempo[tiempo] = arrayTiempo[tiempo] + 1;
        }
      }

      if (tiempo == 0) {
        mesas = arrayTiempo[tiempo];
      }

      if (tiempo > 0) {
        if (mesas < arrayTiempo[tiempo]) {
          mesas = arrayTiempo[tiempo];
        }
      }
    }
    cout << mesas;
    return 0;
  }
}