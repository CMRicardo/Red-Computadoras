#include "../Headers/Menu.h"
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
       << "6 - Exit" << endl
       << "-----------------------" << endl
       << "Enter an option [1 - 6]: ";
}