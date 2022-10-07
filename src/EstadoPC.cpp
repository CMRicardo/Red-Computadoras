#include "Headers/Network.h"
using namespace std;

void Red::encenderComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (cpus[index].estaEncendida) {
    cout << "PC #" << index + 1 << " ya esta encendida" << endl;
  } else {
    cout << "PC #" << index + 1 << " encendida" << endl;
    cpus[index].estaEncendida = true;
  }
}

void Red::apagarComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (!cpus[index].estaEncendida) {
    cout << "PC #" << index + 1 << " ya esta apagada" << endl;
  } else {
    cout << "PC #" << index + 1 << " apagada" << endl;
    cpus[index].estaEncendida = false;
  }
}