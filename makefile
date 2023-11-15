# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic
SRC = main.cpp CutBox.cpp CutEllipsoid.cpp CutSphere.cpp CutVoxel.cpp Interpretador.cpp PutBox.cpp PutSphere.cpp PutEllipsoid.cpp PutVoxel.cpp Sculptor.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = meu_programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
