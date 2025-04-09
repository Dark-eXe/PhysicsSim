# Compiler
CXX = clang++

# Get macOS SDK path dynamically
SYSROOT = $(shell xcrun --show-sdk-path)

# Compiler flags
CXXFLAGS = -std=c++17 -isysroot $(SYSROOT) -I/opt/homebrew/include

# Linker flags
LDFLAGS = -L/opt/homebrew/lib -lglew -lglfw -framework OpenGL

# Source files
SRC = main.cpp

# Output binary
OUT = main

# Build rule
all:
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(OUT)

# Clean build
clean:
	rm -f $(OUT)
