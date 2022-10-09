#pragma once
#include <iostream>

#include "Constantes.h"

class Computadora {
 public:
  int id;
  int disco;
  bool estaEncendida;
  bool estaConectada;

  Computadora();

  void mostrarInformacion();
};