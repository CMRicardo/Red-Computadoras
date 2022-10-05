#pragma once
class Computer {
 public:
  int id;
  int disk;
  bool isTurnedOn;
  bool isConnected;

  Computer();

  void showInfo();
};