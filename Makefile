BIN = bin
SRC = src
OBJ = obj
CXX = clang
CPPFLAGS  =
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(OBJ)/, $(notdir $(SOURCES:.cpp=.o)))

target = Red-Computadoras

all: $(BIN)/$(target)

$(BIN)/$(target): $(OBJS)
	@echo Creando $@... con $^
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo Creando $@... con $^
	$(CXX) $(CPPFLAGS) -c $< -o $@

# ************ Limpieza ************
.PHONY: clean
clean :
	@echo Limpiando archivos intermedios...
	rm $(OBJ)/*
	rm $(BIN)/*
