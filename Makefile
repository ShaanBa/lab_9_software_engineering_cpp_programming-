# Compiler
CXX = g++

# Compiler flags
# -std=c++11: Use the C++11 standard (good, modern baseline)
# -Wall:      Turn on all common warnings (good practice)
CXXFLAGS = -std=c++11 -Wall

# The name of your final executable
TARGET = matrix_app

# All .cpp source files
SOURCES = main.cpp matrix_operations.cpp

# All .o object files, generated from the .cpp files
OBJECTS = $(SOURCES:.cpp=.o)

# The default rule (builds the executable)
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile main.cpp into main.o
main.o: main.cpp matrix_operations.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile matrix_operations.cpp into matrix_operations.o
matrix_operations.o: matrix_operations.cpp matrix_operations.h
	$(CXX) $(CXXFLAGS) -c matrix_operations.cpp

# Rule to clean up (remove compiled files)
clean:
	rm -f $(TARGET) $(OBJECTS)