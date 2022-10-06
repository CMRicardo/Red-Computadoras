#include "../Headers/Menu.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void PrintMenu() {
  cout << "MAIN MENU" << endl
       << "-----------------------" << endl
       << "1 - Show PCs" << endl
       << "2 - Turn on a PC" << endl
       << "3 - Turn off a PC" << endl
       << "4 - Connect network" << endl
       << "5 - Disconnect network" << endl
       << "6 - Download file" << endl
       << "7 - Copy file" << endl
       << "8 - Exit" << endl
       << "-----------------------" << endl
       << "Enter an option [1 - 8]: ";
}

void Imprimir_Creditos() {
  system("cls");
  cout << "CREDITOS" << endl
       << "-----------------------" << endl
       << "Integrantes: " << endl
       << "Ricardo Corrales " << endl
       << "Walther Guerra " << endl
       << endl
       << "Clase: " << endl
       << "Lenguaje de Programacion 3 " << endl
       << endl
       << "Seccion: " << endl
       << "0900 " << endl
       << endl
       << "-----------------------" << endl;
}