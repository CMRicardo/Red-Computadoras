#include "../Headers/Computer.h"

#include <iostream>

#include "../Headers/Constants.h"

using namespace std;

Computer::Computer() {
  id = DOES_NOT_EXIST;
  disk = INITIAL_DISK;
  isTurnedOn = false;
  isConnected = false;
}

/**
 * The function showInfo() prints the id, disk, power, and net status of the
 * computer
 */
void Computer::showInfo() {
  cout << "ID: " << id << endl
       << "Disk: " << disk << " GB" << endl
       << "Power: " << (isTurnedOn ? "ON" : "OFF") << endl
       << "Net status: " << (isConnected ? "CONNECTED" : "DISCONNECTED")
       << endl;
}
