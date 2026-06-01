# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Target
TARGET := $(BUILD_DIR)/app.exe

# Source files
SRC := $(wildcard $(SRC_DIR)/*.cpp)

# Object files go into build/
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp -> .o in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean
clean:
	rm -Rf $(BUILD_DIR) 2>NULL