#pragma once
#include <iostream>

#include "../Headers/Constants.h"

class Computer {
 public:
  int id;
  int disk;
  bool isTurnedOn;
  bool isConnected;

  Computer();

  void showInfo();
};