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

void Computer::showInfo() {
  cout << "ID: " << id << endl
       << "Disk: " << disk << " GB" << endl
       << "Power: " << (isTurnedOn ? "on" : "off") << endl
       << "Net status: " << (isConnected ? "Connected" : "Disconnected")
       << endl;
}
