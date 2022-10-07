#include <stdlib.h>

#include <iostream>

#include "../Headers/Constants.h"
#include "../Headers/Imprimir.h"
#include "../Headers/Network.h"

using namespace std;

int main() {
  // Contiene todas las PCs del laboratorio
  Red red;
  int opcionSeleccionada = NO_EXISTE;

  do {
    // Limpia la pantalla en cada iteración
    system("cls");
    imprimirMenu();
    cin >> opcionSeleccionada;

    switch (opcionSeleccionada) {
      case MOSTRAR_INFORMACION:
        red.mostrarRed();
        break;
      case ENCENDER:
        red.encenderComputadora();
        break;
      case APAGAR:
        red.apagarComputadora();
        break;
      case CONECTAR_RED:
        red.conectarRed();
        break;
      case DESCONECTAR_RED:
        red.desconectarRed();
        break;
      case DESCARGAR_ARCHIVO:
        red.descargarArchivo();
        break;
      case COPIAR_ARCHIVO:
        red.copiarArchivo();
        break;
      case SALIR:
        imprimirCreditos();
        break;
      default:
        cout << "ERROR: Opcion desconocida" << endl;
        break;
    }
    // Pausa la ejecución del programa después de cada iteración
    system("pause");
  } while (opcionSeleccionada != SALIR);
}