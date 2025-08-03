CXX = clang++
CXXFLAGS = -std=c++17 -I/usr/local/opt/sfml/include
LDFLAGS = -L/usr/local/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

all: sfml-app

sfml-app: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o sfml-app $(LDFLAGS)

clean:
	rm -f sfml-app
