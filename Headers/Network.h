#pragma once
#include <stdlib.h>

#include <iostream>

#include "Computer.h"
#include "Constants.h"

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
  void copyFile();

 private:
  int getIndex();
};