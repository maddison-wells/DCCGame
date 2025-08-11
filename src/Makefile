CXX = clang++
CXXFLAGS = -std=c++17 -I/usr/local/opt/sfml/include
LDFLAGS = -L/usr/local/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = class/Math.cpp class/Carl.cpp class/Donut.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: dcc-app

dcc-app: $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) dcc-app
