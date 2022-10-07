#include "../Headers/Imprimir.h"

using namespace std;

void imprimirMenu() {
  cout << "MENU PRINCIPAL" << endl
       << "-----------------------" << endl
       << "1 - Mostrar PCs" << endl
       << "2 - Encender una PC" << endl
       << "3 - Apagar una PC" << endl
       << "4 - Conectar PC a la red" << endl
       << "5 - Desconectar PC a la red" << endl
       << "6 - Descargar archivo" << endl
       << "7 - Copiar archivo" << endl
       << "8 - Salir" << endl
       << "-----------------------" << endl
       << "Ingresa una opcion [1 - 8]: ";
}

void imprimirCreditos() {
  system("cls");
  cout << "CREDITOS" << endl
       << "-----------------------" << endl
       << "Integrantes:" << endl
       << "- Ricardo Corrales" << endl
       << "- Walther Guerra" << endl
       << endl
       << "Clase:" << endl
       << "Lenguajes de Programacion III" << endl
       << endl
       << "Seccion:" << endl
       << "0900" << endl
       << endl
       << "-----------------------" << endl;
}