# Main variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -pg -Iinclude
LDFLAGS = 
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/tp1.out

# Source files and objects
SRCS = tp1.cpp $(SRC_DIR)/aux.cpp $(SRC_DIR)/ordalg.cpp $(SRC_DIR)/ordind.cpp $(SRC_DIR)/pessoa.cpp $(SRC_DIR)/memlog.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default rule
all: $(TARGET)

# Compilation rule
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rule to clean and compile from zero
rebuild: clean all

# Dependency tracking for .o files
-include $(OBJS:.o=.d)
