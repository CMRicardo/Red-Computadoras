#include "Headers/Computer.h"
#include "Headers/Constants.h"
#include "Headers/Menu.h"
#include "Headers/Network.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  // Contains all of the PCs in the lab
  Network net;
  int selectedOption = DOES_NOT_EXIST;

  do {
    // Clears the screen in each iteration
    system("cls");
    PrintMenu();
    cin >> selectedOption;

    switch (selectedOption) {
    case SHOW_INFO:
      net.showNetwork();
      break;
    case TURN_ON:
      net.turnOnComputer();
      break;
    case TURN_OFF:
      net.turnOffComputer();
      break;
    case CONNECT_NET:
      break;
    case DISCONNECT_NET:
      break;
    case EXIT:
      cout << "Goodbye!" << endl;
      break;
    default:
      cout << "ERROR: Unknown option" << endl;
      break;
    }
    // Pauses the app execution after each iteration
    system("pause");
  } while (selectedOption != EXIT);
}