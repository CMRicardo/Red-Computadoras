#include "../Headers/Computer.h"

using namespace std;

Computer::Computer() {
  id = DOES_NOT_EXIST;
  disk = INITIAL_DISK;
  isTurnedOn = false;
  isConnected = false;
}

void Computer::showInfo() {
  cout << "ID: " << id << endl
       << "Disk: " << disk << " GB" << endl
       << "Power: " << (isTurnedOn ? "ON" : "OFF") << endl
       << "Net status: " << (isConnected ? "CONNECTED" : "DISCONNECTED")
       << endl;
}
