EXECUTABLE = Red-Computadoras.exe
CC = clang

# Compiles the program
all: ObjectFiles/Main.o ObjectFiles/Computer.o ObjectFiles/Menu.o ObjectFiles/Network.o
	$(CC) $? -o $(EXECUTABLE)

ObjectFiles/Main.o: Main.cpp ./Headers/Constants.h
	$(CC) -c Main.cpp -o ./$@

ObjectFiles/Computer.o: ./Utilities/Computer.cpp ./Headers/Computer.h ./Headers/Constants.h
	$(CC) -c ./Utilities/Computer.cpp -o ./$@

ObjectFiles/Menu.o: ./Utilities/Menu.cpp ./Headers/Menu.h
	$(CC) -c ./Utilities/Menu.cpp -o ./$@

ObjectFiles/Network.o: ./Utilities/Network.cpp ./Headers/Network.h ./Headers/Constants.h
	$(CC) -c ./Utilities/Network.cpp -o ./$@

# Cleans temporary files
clean:
	rm -f ./ObjectFiles/*.o $(EXECUTABLE)