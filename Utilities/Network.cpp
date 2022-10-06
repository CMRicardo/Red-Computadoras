#include "../Headers/Network.h"

using namespace std;

Red::Red() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cpus[i].id = ID_BASE + i;
  }
}

int Red::obtenerIndex() {
  int index = NO_EXISTE;
  int idPC;
  cout << "Ingresa el id de la PC: ";
  cin >> idPC;

  for (int i = 0; i < MAX_CPUS; i++) {
    if (cpus[i].id == idPC) {
      index = i;
      break;
    }
  }

  return index;
}

void Red::mostrarRed() {
  for (int i = 0; i < MAX_CPUS; i++) {
    cout << "-----------------------" << endl << "PC #" << i + 1 << endl;
    cpus[i].mostrarInformacion();
    cout << "-----------------------" << endl;
  }
}

void Red::encenderComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
  } else {
    if (cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " ya esta encendida" << endl;
    } else {
      cout << "PC #" << index + 1 << " encendida" << endl;
      cpus[index].estaEncendida = true;
    }
  }
}

void Red::apagarComputadora() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " ya esta apagada" << endl;
    } else {
      cout << "PC #" << index + 1 << " apagada" << endl;
      cpus[index].estaEncendida = false;
    }
  }
}

void Red::conectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " esta apagada!" << endl
           << "No se puede conectar a la red" << endl;
    } else if (cpus[index].estaConectada) {
      cout << "PC #" << index + 1 << " ya esta conectada" << endl;
    } else {
      cout << "PC #" << index + 1 << " conectada a la red" << endl;
      cpus[index].estaConectada = true;
    }
  }
}

void Red::desconectarRed() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
  } else {
    if (!cpus[index].estaEncendida) {
      cout << "PC #" << index + 1 << " esta apagada!" << endl;
    } else if (!cpus[index].estaConectada) {
      cout << "PC #" << index + 1 << " ya esta desconectada" << endl;
    } else {
      cout << "PC #" << index + 1 << " desconectada de la red" << endl;
      cpus[index].estaConectada = false;
    }
  }
}

int generarNumeroAleatorio() { return rand() % 512 + 1; }

void Red::descargarArchivo() {
  int index = obtenerIndex();

  if (index == NO_EXISTE) {
    cout << "ERROR: La PC no existe" << endl;
    return;
  }

  if (cpus[index].estaEncendida) {
    if (cpus[index].estaConectada) {
      int pesoArchivo = generarNumeroAleatorio();
      cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

      if (cpus[index].disco >= pesoArchivo) {
        cpus[index].disco -= pesoArchivo;
        cout << "Hay espacio suficiente" << endl
             << "Descargando..." << endl
             << "El espacio restante es: " << cpus[index].disco << " GB"
             << endl;
      } else {
        cout << "Espacio insuficiente :(" << endl;
      }

    } else {
      cout << "No esta conectada" << endl;
    }
  } else {
    cout << "No esta encendida" << endl;
  }
}

void Red::copiarArchivo() {
  cout << "------------------RECEPTOR------------------" << endl;
  int indexReceptor = obtenerIndex();
  cout << "------------------EMISOR------------------" << endl;
  int indexEmisor = obtenerIndex();

  if (indexReceptor == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }
  if (indexEmisor == NO_EXISTE) {
    cout << "ERROR: ID doesn't exist" << endl;
    return;
  }

  bool estanEncendidas =
      cpus[indexReceptor].estaEncendida && cpus[indexEmisor].estaEncendida;
  bool estanConectadas =
      cpus[indexReceptor].estaConectada && cpus[indexEmisor].estaConectada;

  if (estanEncendidas) {
    if (estanConectadas) {
      int pesoArchivo = generarNumeroAleatorio();
      cout << "El peso del archivo es: " << pesoArchivo << " GB" << endl;

      bool hayEspacioSuficiente = cpus[indexReceptor].disco >= pesoArchivo;
      if (hayEspacioSuficiente) {
        cpus[indexReceptor].disco -= pesoArchivo;
        cout << "Hay espacio suficiente" << endl
             << "Copiando..." << endl
             << "El espacio restante es: " << cpus[indexReceptor].disco << " GB"
             << endl;
      } else {
        cout << "Espacio insuficiente :(" << endl;
      }

    } else if (!estanConectadas) {
      cout << "No estan conectadas" << endl;
    } else if (!cpus[indexReceptor].estaConectada) {
      cout << "ERROR: La PC receptora no esta conectada" << endl;
    } else if (!cpus[indexEmisor].estaConectada) {
      cout << "ERROR: La PC emisora no esta conectada" << endl;
    }
  } else if (!estanEncendidas) {
    cout << "No estan encendidas" << endl;
  } else if (!cpus[indexReceptor].estaEncendida) {
    cout << "ERROR: La PC receptora no esta encendida" << endl;
  } else if (!cpus[indexEmisor].estaEncendida) {
    cout << "ERROR: La PC emisora no esta encendida" << endl;
  }
}