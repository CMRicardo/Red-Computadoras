#include <stdlib.h>

#include <iostream>

#include "Headers/Computer.h"
#include "Headers/Constants.h"
#include "Headers/Imprimir.h"
#include "Headers/Network.h"

using namespace std;

int main() {
  // Contiene todas las PCs del laboratorio
  Red red;
  int selectedOption = NO_EXISTE;

  do {
    // Limpia la pantalla en cada iteración
    system("cls");
    imprimirMenu();
    cin >> selectedOption;

    switch (selectedOption) {
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
        cout << "ERROR: Unknown option" << endl;
        break;
    }
    // Pausa la ejecución del programa después de cada iteración
    system("pause");
  } while (selectedOption != SALIR);
}