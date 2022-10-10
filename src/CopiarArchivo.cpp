#include "Headers/Red.h"
using namespace std;

void Red::copiarArchivo() {
  cout << "------------------RECEPTOR------------------" << endl;
  int indexReceptor = obtenerIndex();
  if (indexReceptor == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }
  if (!cpus[indexReceptor].estaEncendida) {
    cout << "PC #" << indexReceptor + 1 << " no esta encendida" << endl;
    return;
  }
  if (!cpus[indexReceptor].estaConectada) {
    cout << "PC #" << indexReceptor + 1 << " no esta conectada a la red"
         << endl;
    return;
  }

  cout << "------------------EMISOR------------------" << endl;
  int indexEmisor = obtenerIndex();
  if (indexEmisor == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }
  if (!cpus[indexEmisor].estaEncendida) {
    cout << "PC #" << indexEmisor + 1 << " no esta encendida" << endl;
    return;
  }
  if (!cpus[indexEmisor].estaConectada) {
    cout << "PC #" << indexEmisor + 1 << " no esta conectada a la red" << endl;
    return;
  }

  int pesoArchivo = generarNumeroAleatorio();
  cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

  bool hayEspacioSuficiente = cpus[indexReceptor].disco >= pesoArchivo;
  if (!hayEspacioSuficiente) {
    cout << "Espacio insuficiente :(" << endl;
    return;
  }

  cpus[indexReceptor].disco -= pesoArchivo;
  cout << "Hay espacio suficiente " << endl
       << "Copiando..." << endl << endl;
       system ("pause");

       cout << "El espacio restante es: " << cpus[indexReceptor].disco << " GB" << endl
       << endl;
}