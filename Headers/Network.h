#pragma once
#include "../Headers/Constants.h"
#include "Computer.h"

class Network {
public:
  Computer cpus[MAX_CPUS];

  Network();

  void showNetwork();

  void turnOnComputer();
  void turnOffComputer();

  void connectNetwork();
  void disconnectNetwork();

  void downloadFile();

private:
  int getIndex();
};