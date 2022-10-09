#pragma once
#include <stdlib.h>

#include <iostream>

#include "Computadora.h"
#include "Constantes.h"

class Red {
 public:
  Computadora cpus[MAX_CPUS];

  Red();

  void mostrarRed();

  void encenderComputadora();
  void apagarComputadora();

  void conectarRed();
  void desconectarRed();

  void descargarArchivo();
  void copiarArchivo();

 private:
  int obtenerIndex();
  int generarNumeroAleatorio();
};