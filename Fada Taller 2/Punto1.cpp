/**
Sebastian Peñaranda
Luis Belalcazar
Punto 1 Taller 2 ADA I
*/


#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

/**
Recibir los datos de entrada:41
1
N-> Número de clientes : 1> N <= 10^4
A->Tiempo de atención por persona 𝐴𝑖 (0 ≤ 𝑖 < 𝑁)
T->  Tiempo máximo de atención  1 ≤ 𝑇 ≤ 10^9

*/
int main(int argc, char *argv[]) {
  int personas;
  cout << "Escriba la cantidad de personas: ";
  cin >> personas;

  int tiempoCliente;
  cout << "Escriba el tiempo maximo que quiere que demore un cliente en ser "
          "atendido: ";
  cin >> tiempoCliente;

  int tiempoA[personas];
  for (int i = 0; i < personas; i++) {
    cout << "Escriba el siguiente tiempo de atencion, son un total de "
         << personas << ": ";
    cin >> tiempoA[i];
  }
// cambiar los valores del array Puestos en el tiempo maximo de atencion
  int puestos[personas];
  for (int i = 0; i < personas; i++) {
    puestos[i] = tiempoCliente;
  }
// Funcion principal encargada de calcular la cantidad minimo de puestos necesarios para atender simultaneamente a todos los clientes en una cantidad de tiempo determinada.
  int i = 0;
  int j = 0;
  int cantidadPersonas = personas;
  while (cantidadPersonas > 0) {
    while ((puestos[i] - tiempoA[j]) >= 0) {
      puestos[i] = puestos[i] - tiempoA[j];
      cantidadPersonas--;
      j++;
      i = 0;
    }
    i++;
  }

  /**
  Funcion auxiliar encargada de contar cuantos valores diferentes al 
   tiempo maximo hay en el array, solamente contando hasta la cantidad 
   de personas suministradas ya que el peor caso seria que hubieran n 
   puestos.
 */
  
  int contadorFinal = 0;
  for (int x = 0; x <= personas - 1; x++) {
    if (puestos[x] != tiempoCliente) {
      contadorFinal++;
    }
    
  }
  std::cout << contadorFinal;
  return 0;
}