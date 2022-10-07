#include "Headers/Network.h"

using namespace std;

Red::Red() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cpus[i].id = ID_BASE + i;
  }
}

int Red::obtenerIndex() {
  int index = NO_EXISTE;
  int idPC;
  cout << "Ingresa el id de la PC: ";
  cin >> idPC;

  for (int i = 0; i < MAX_CPUS; i++) {
    if (cpus[i].id == idPC) {
      index = i;
      break;
    }
  }

  return index;
}

void Red::mostrarRed() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cout << "-----------------------" << endl << "PC #" << i + 1 << endl;
    cpus[i].mostrarInformacion();
    cout << "-----------------------" << endl;
  }
}

int Red::generarNumeroAleatorio() { return rand() % TAMANIO_MAXIMO + 1; }
