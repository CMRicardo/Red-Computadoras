#include "../Headers/Network.h"

#include <stdlib.h>

#include <iostream>

#include "../Headers/Constants.h"

using namespace std;

/**
 * The constructor for the Network class initializes the id field of each CPU
 * object in the cpus array to a unique value
 */
Network::Network() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cpus[i].id = BASE_ID + i;
  }
}

/**
 * The function asks the user to enter a valid id, then it loops through the
 * array of computers and returns the index of the computer with the id that the
 * user entered
 *
 * @return The index of the computer in the array.
 */
int Network::getIndex() {
  int index = DOES_NOT_EXIST;
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
void Network::showNetwork() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cout << "-----------------------" << endl << "PC #" << i + 1 << endl;
    cpus[i].showInfo();
    cout << "-----------------------" << endl;
  }
}

/**
 * The function `turnOnComputer()` turns on a computer if it's not already
 * turned on
 */
void Network::turnOnComputer() {
  int index = getIndex();

  if (index == DOES_NOT_EXIST) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (cpus[index].isTurnedOn) {
      cout << "PC #" << index + 1 << " was already turned on" << endl;
    } else {
      cout << "PC #" << index + 1 << " turned on" << endl;
      cpus[index].isTurnedOn = true;
    }
  }
}

/**
 * The function gets the index of the computer to turn off, checks if the index
 * is valid, and if it is, checks if the computer is already turned off, and if
 * it isn't, turns it off
 */
void Network::turnOffComputer() {
  int index = getIndex();

  if (index == DOES_NOT_EXIST) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].isTurnedOn) {
      cout << "PC #" << index + 1 << " was already turned off" << endl;
    } else {
      cout << "PC #" << index + 1 << " turned off" << endl;
      cpus[index].isTurnedOn = false;
    }
  }
}

/**
 * If the ID exists, and the PC is turned on, and the PC is not already
 * connected, then connect the PC to the network
 */
void Network::connectNetwork() {
  int index = getIndex();

  if (index == DOES_NOT_EXIST) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].isTurnedOn) {
      cout << "PC #" << index + 1 << " is turned off!" << endl
           << "Can't connect to the network" << endl;
    } else if (cpus[index].isConnected) {
      cout << "PC #" << index + 1 << " is already connected" << endl;
    } else {
      cout << "PC #" << index + 1 << " connected to the network" << endl;
      cpus[index].isConnected = true;
    }
  }
}

/**
 * The function disconnectNetwork() disconnects a computer from the network
 */
void Network::disconnectNetwork() {
  int index = getIndex();

  if (index == DOES_NOT_EXIST) {
    cout << "ERROR: ID doesn't exist" << endl;
  } else {
    if (!cpus[index].isTurnedOn) {
      cout << "PC #" << index + 1 << " is turned off!" << endl;
    } else if (!cpus[index].isConnected) {
      cout << "PC #" << index + 1 << " is already disconnected" << endl;
    } else {
      cout << "PC #" << index + 1 << " disconnected of the network" << endl;
      cpus[index].isConnected = false;
    }
  }
}

int generarNumeroAleatorio() { return rand() % 512 + 1; }

void Network::downloadFile() {
  int index = getIndex();

  if (index == DOES_NOT_EXIST) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }

  if (cpus[index].isTurnedOn) {
    if (cpus[index].isConnected) {
      int pesoArchivo = generarNumeroAleatorio();
      cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

      if (cpus[index].disk >= pesoArchivo) {
        cpus[index].disk -= pesoArchivo;
        cout << "Hay espacio suficiente" << endl
             << "Descargando..." << endl
             << "El espacio restante es: " << cpus[index].disk << "GB" << endl;
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