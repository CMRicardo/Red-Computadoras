#pragma once
// Número máximo de PCs en el laboratorio
const int MAX_CPUS = 5;
// Lo usamos para indicar que algo no existe
const int NO_EXISTE = -1;
// La id base para identificar los PCs
const int ID_BASE = 1000;
// Almacenamiento disponible por defecto
const int DISCO_INICIAL = 1024;
// Tamaño máximo de archivo
const int TAMANIO_MAXIMO = 512;
// Opciones del programa
enum OPCIONES {
  MOSTRAR_INFORMACION = 1,
  ENCENDER,
  APAGAR,
  CONECTAR_RED,
  DESCONECTAR_RED,
  DESCARGAR_ARCHIVO,
  COPIAR_ARCHIVO,
  SALIR
};