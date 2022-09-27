OBJECT_FILES = Main.o Computer.o Menu.o Network.o
EXECUTABLE = Red-Computadoras.exe
COMPILER = clang

# Compiles the program
all: $(OBJECT_FILES)
	$(COMPILER) $(OBJECT_FILES) -o $(EXECUTABLE)

Main.o: Main.cpp ./Headers/Constants.h
	$(COMPILER) -c Main.cpp

Computer.o: ./Utilities/Computer.cpp ./Headers/Computer.h ./Headers/Constants.h
	$(COMPILER) -c ./Utilities/Computer.cpp

Menu.o: ./Utilities/Menu.cpp ./Headers/Menu.h
	$(COMPILER) -c ./Utilities/Menu.cpp

Network.o: ./Utilities/Network.cpp ./Headers/Network.h ./Headers/Constants.h
	$(COMPILER) -c ./Utilities/Network.cpp

# Cleans temporary files
clean:
	rm -f $(OBJECT_FILES) $(EXECUTABLE)