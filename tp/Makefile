# Variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g -Iinclude
LDFLAGS = 
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/tp1.out

# Arquivos fonte e objetos
SRCS = tp1.cpp $(SRC_DIR)/aux.cpp $(SRC_DIR)/ordalg.cpp $(SRC_DIR)/ordind.cpp $(SRC_DIR)/pessoa.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Regras
all: $(TARGET)

# Regra para compilar o binário final
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# Regra para compilar os arquivos .cpp em .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Regra para limpar e compilar do zero
rebuild: clean all

# Declaração de diretórios de dependência
-include $(OBJS:.o=.d)
