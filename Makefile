# Compiler and Qt tools
CXX = g++-11
CXXFLAGS = -I$(QT_DIR)/include -I$(QT_DIR)/include/QtWidgets -I$(INCLUDE_DIR) -std=c++17
LDFLAGS = -F$(QT_DIR)/lib  -framework QtWidgets -framework QtCore -framework QtGui

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
QT_DIR = /opt/homebrew/Cellar/qt/6.7.3

# Target executable
TARGET = quantum_circuit

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link objects to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files into objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)