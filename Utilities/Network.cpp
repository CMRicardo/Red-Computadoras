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

void Red::descargarArchivo() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (!cpus[index].estaEncendida) {
    cout << "No esta encendida" << endl;
    return;
  }

  if (!cpus[index].estaConectada) {
    cout << "No esta conectada a la red" << endl;
    return;
  }

  int pesoArchivo = generarNumeroAleatorio();
  cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

  bool hayEspacioDisponible = cpus[index].disco >= pesoArchivo;
  if (!hayEspacioDisponible) {
    cout << "Espacio insuficiente :(" << endl;
    return;
  }

  cpus[index].disco -= pesoArchivo;
  cout << endl
       << "Hay espacio suficiente" << endl
       << endl
       << "Descargando..." << endl
       << endl
       << "El espacio restante es: " << cpus[index].disco << " GB" << endl;
}
