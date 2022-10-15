# ¿Dondé guardamos el ejecutable?
BIN = bin
# ¿Dondé está el código fuente?
SRC = src
# ¿Dondé guardamos los archivos objeto?
OBJ = obj
# ¿Qué compilador usamos?
CXX = clang
# ¿Qué flags utilizamos al compilar?
CPPFLAGS  =
# Los nombres de los archivos .cpp
SOURCES = $(wildcard $(SRC)/*.cpp)
# Los nombres de los archivos objeto
OBJS = $(addprefix $(OBJ)/, $(notdir $(SOURCES:.cpp=.o)))
# ¿Cómo se llamará el archivo ejecutable?
target = Red-Computadoras
# Instrucción por defecto
all: $(BIN)/$(target)
# Crea el archivo ejecutable
$(BIN)/$(target): $(OBJS)
	@echo Creando $@... con $^
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@
# Crea los archivos objeto a partir de los .cpp
$(OBJ)/%.o: $(SRC)/%.cpp
	@echo Creando $@... con $^
	$(CXX) $(CPPFLAGS) -c $< -o $@

# Limpieza de los archivos objeto y el ejecutable
.PHONY: clean
clean :
	@echo Limpiando archivos intermedios...
	rm $(OBJ)/*
	rm $(BIN)/*
