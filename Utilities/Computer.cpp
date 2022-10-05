#include "../Headers/Computer.h"
#include "../Headers/Constants.h"
#include <iostream>
using namespace std;

Computer::Computer() {
  id = DOES_NOT_EXIST;
  disk = 1024;
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
