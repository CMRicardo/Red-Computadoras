#include "Headers/Computer.h"

using namespace std;

Computadora::Computadora() {
  id = NO_EXISTE;
  disco = DISCO_INICIAL;
  estaEncendida = false;
  estaConectada = false;
}

void Computadora::mostrarInformacion() {
  cout << "ID: " << id << endl
       << "Disco: " << disco << " GB" << endl
       << "Estado: " << (estaEncendida ? "ENCENDIDA" : "APAGADA") << endl
       << "Estado de red: " << (estaConectada ? "CONECTADA" : "DESCONECTADA")
       << endl;
}
