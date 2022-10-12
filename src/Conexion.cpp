#include "Headers/Red.h"
using namespace std;

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