# Compiler settings - Updated to use the absolute path to your MSYS2 installation
CXX = C:/msys64/ucrt64/bin/g++.exe
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directory mappings
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/app.exe

# Manually list your source files to ensure Windows/MSYS paths read them perfectly
SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/ChangeMaker.cpp \
       $(SRCDIR)/DivisionCounter.cpp \
       $(SRCDIR)/Vector.cpp \
       $(SRCDIR)/Animal.cpp

# Convert source file strings into object files inside the build directory
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))

# Default build rule
all: $(TARGET)

# Linker rule: Combines the compiled object files into the final app executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILDDIR)
	$(CXX) -o $(TARGET) $(OBJS)

# Compilation rule: Turns each individual .cpp file into a .o file
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to clear out old build artifacts
clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean