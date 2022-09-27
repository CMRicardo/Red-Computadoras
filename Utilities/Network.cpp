#include "../Headers/Network.h"
#include "../Headers/Constants.h"

#include <iostream>
using namespace std;

Network::Network() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cpus[i].id = BASE_ID + i;
  }
}

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

void Network::showNetwork() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cout << "-----------------------" << endl << "PC #" << i + 1 << endl;
    cpus[i].showInfo();
    cout << "-----------------------" << endl;
  }
}

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
