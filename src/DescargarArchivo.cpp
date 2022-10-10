#include "Headers/Red.h"
using namespace std;

void Red::descargarArchivo() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (!cpus[index].estaEncendida) {
    cout << "No esta encendida" << endl;
    return;
  }

  if (!cpus[index].estaConectada) {
    cout << "No esta conectada a la red" << endl;
    return;
  }

  int pesoArchivo = generarNumeroAleatorio();
  cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

  bool hayEspacioDisponible = cpus[index].disco >= pesoArchivo;
  if (!hayEspacioDisponible) {
    cout << "Espacio insuficiente :(" << endl;
    return;
  }

  cpus[index].disco -= pesoArchivo;
  cout << endl
       << "Hay espacio suficiente" << endl
       << endl
       << "Descargando..." << endl
       << endl;
  system("pause");

  cout << endl
       << "El espacio restante es: " << cpus[index].disco << " GB" << endl;
}
