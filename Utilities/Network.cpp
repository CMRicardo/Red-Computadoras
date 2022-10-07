#include "../Headers/Network.h"

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

void Red::conectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (!cpus[index].estaEncendida) {
    cout << "PC #" << index + 1 << " esta apagada!" << endl
         << "No se puede conectar a la red" << endl;
  } else if (cpus[index].estaConectada) {
    cout << "PC #" << index + 1 << " ya esta conectada" << endl;
  } else {
    cout << "PC #" << index + 1 << " conectada a la red" << endl;
    cpus[index].estaConectada = true;
  }
}

void Red::desconectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (!cpus[index].estaEncendida) {
    cout << "PC #" << index + 1 << " esta apagada!" << endl;
  } else if (!cpus[index].estaConectada) {
    cout << "PC #" << index + 1 << " ya esta desconectada" << endl;
  } else {
    cout << "PC #" << index + 1 << " desconectada de la red" << endl;
    cpus[index].estaConectada = false;
  }
}

int Red::generarNumeroAleatorio() { return rand() % TAMANIO_MAXIMO + 1; }
