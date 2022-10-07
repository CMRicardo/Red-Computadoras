#pragma once
#include <iostream>

#include "Constants.h"

class Computadora {
 public:
  int id;
  int disco;
  bool estaEncendida;
  bool estaConectada;

  Computadora();

  void mostrarInformacion();
};