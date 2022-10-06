#include "../Headers/Network.h"

using namespace std;

/**
 * The constructor for the Network class initializes the id field of each CPU
 * object in the cpus array to a unique value
 */
Red::Red() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cpus[i].id = ID_BASE + i;
  }
}

/**
 * The function asks the user to enter a valid id, then it loops through the
 * array of computers and returns the index of the computer with the id that the
 * user entered
 *
 * @return The index of the computer in the array.
 */
int Red::obtenerIndex() {
  int index = NO_EXISTE;
  int idPC;
  cout << "Enter a valid id: ";
  cin >> idPC;

  for (int i = 0; i < MAX_CPUS; i++) {
    if (cpus[i].id == idPC) {
      index = i;
      break;
    }
  }

  return index;
}

/**
 * It displays the information of each computer in the network
 */
void Red::mostrarRed() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cout << "-----------------------" << endl << "PC #" << i + 1 << endl;
    cpus[i].mostrarInformacion();
    cout << "-----------------------" << endl;
  }
}

/**
 * The function `turnOnComputer()` turns on a computer if it's not already
 * turned on
 */
void Red::encenderComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " was already turned on" << endl;
    } else {
      cout << "PC #" << index + 1 << " turned on" << endl;
      cpus[index].estaEncendida = true;
    }
  }
}

void Red::apagarComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " was already turned off" << endl;
    } else {
      cout << "PC #" << index + 1 << " turned off" << endl;
      cpus[index].estaEncendida = false;
    }
  }
}

/**
 * If the ID exists, and the PC is turned on, and the PC is not already
 * connected, then connect the PC to the network
 */
void Red::conectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " is turned off!" << endl
           << "Can't connect to the network" << endl;
    } else if (cpus[index].estaConectada) {
      cout << "PC #" << index + 1 << " is already connected" << endl;
    } else {
      cout << "PC #" << index + 1 << " connected to the network" << endl;
      cpus[index].estaConectada = true;
    }
  }
}

/**
 * The function disconnectNetwork() disconnects a computer from the network
 */
void Red::desconectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " is turned off!" << endl;
    } else if (!cpus[index].estaConectada) {
      cout << "PC #" << index + 1 << " is already disconnected" << endl;
    } else {
      cout << "PC #" << index + 1 << " disconnected of the network" << endl;
      cpus[index].estaConectada = false;
    }
  }
}

int generarNumeroAleatorio() { return rand() % 512 + 1; }

void Red::descargarArchivo() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }

  if (cpus[index].estaEncendida) {
    if (cpus[index].estaConectada) {
      int pesoArchivo = generarNumeroAleatorio();
      cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

      if (cpus[index].disco >= pesoArchivo) {
        cpus[index].disco -= pesoArchivo;
        cout << "Hay espacio suficiente" << endl
             << "Descargando..." << endl
             << "El espacio restante es: " << cpus[index].disco << " GB"
             << endl;
      } else {
        cout << "Espacio insuficiente :(" << endl;
      }

    } else {
      cout << "No esta conectada" << endl;
    }
  } else {
    cout << "No esta encendida" << endl;
  }
}

void Red::copiarArchivo() {
  cout << "------------------RECEPTOR------------------" << endl;
  int indexReceptor = obtenerIndex();
  cout << "------------------EMISOR------------------" << endl;
  int indexEmisor = obtenerIndex();

  if (indexReceptor == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }
  if (indexEmisor == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }

  bool estanEncendidas =
      cpus[indexReceptor].estaEncendida && cpus[indexEmisor].estaEncendida;
  bool estanConectadas =
      cpus[indexReceptor].estaConectada && cpus[indexEmisor].estaConectada;

  if (estanEncendidas) {
    if (estanConectadas) {
      int pesoArchivo = generarNumeroAleatorio();
      cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

      bool hayEspacioSuficiente = cpus[indexReceptor].disco >= pesoArchivo;
      if (hayEspacioSuficiente) {
        cpus[indexReceptor].disco -= pesoArchivo;
        cout << "Hay espacio suficiente" << endl
             << "Copiando..." << endl
             << "El espacio restante es: " << cpus[indexReceptor].disco << " GB"
             << endl;
      } else {
        cout << "Espacio insuficiente :(" << endl;
      }

    } else if (!estanConectadas) {
      cout << "No estan conectadas" << endl;
    } else if (!cpus[indexReceptor].estaConectada) {
      cout << "ERROR: La PC receptora no esta conectada" << endl;
    } else if (!cpus[indexEmisor].estaConectada) {
      cout << "ERROR: La PC emisora no esta conectada" << endl;
    }
  } else if (!estanEncendidas) {
    cout << "No estan encendidas" << endl;
  } else if (!cpus[indexReceptor].estaEncendida) {
    cout << "ERROR: La PC receptora no esta encendida" << endl;
  } else if (!cpus[indexEmisor].estaEncendida) {
    cout << "ERROR: La PC emisora no esta encendida" << endl;
  }
}