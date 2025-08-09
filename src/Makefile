CXX = clang++
CXXFLAGS = -std=c++17 -I/usr/local/opt/sfml/include
LDFLAGS = -L/usr/local/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

all: dcc-app

dcc-app:
	$(CXX) $(CXXFLAGS) class/Carl.cpp main.cpp -o dcc-app $(LDFLAGS)

clean:
	rm -f dcc-app
