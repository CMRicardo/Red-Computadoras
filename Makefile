EXECUTABLE = Red-Computadoras.exe
CC = clang

# Compiles the program
all: ObjectFiles/Main.o ObjectFiles/Computer.o \
ObjectFiles/Imprimir.o ObjectFiles/Network.o \
ObjectFiles/CopiarArchivo.o ObjectFiles/DescargarArchivo.o \
ObjectFiles/EstadoPC.o ObjectFiles/Conexion.o
	$(CC) $? -o $(EXECUTABLE)

ObjectFiles/Main.o: Main.cpp ./Headers/Constants.h
	$(CC) -c Main.cpp -o ./$@

ObjectFiles/Computer.o: ./Utilities/Computer.cpp ./Headers/Computer.h ./Headers/Constants.h
	$(CC) -c ./Utilities/Computer.cpp -o ./$@

ObjectFiles/Imprimir.o: ./Utilities/Imprimir.cpp ./Headers/Imprimir.h
	$(CC) -c ./Utilities/Imprimir.cpp -o ./$@

ObjectFiles/Network.o: ./Utilities/Network.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/Network.cpp -o ./$@

ObjectFiles/CopiarArchivo.o: ./Utilities/CopiarArchivo.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/CopiarArchivo.cpp -o ./$@

ObjectFiles/DescargarArchivo.o: ./Utilities/DescargarArchivo.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/DescargarArchivo.cpp -o ./$@

ObjectFiles/EstadoPC.o: ./Utilities/EstadoPC.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/EstadoPC.cpp -o ./$@

ObjectFiles/Conexion.o: ./Utilities/Conexion.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/Conexion.cpp -o ./$@

# Cleans temporary files
clean:
	rm -f ./ObjectFiles/*.o $(EXECUTABLE)