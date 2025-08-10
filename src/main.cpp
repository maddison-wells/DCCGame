// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>

#include "class/Carl.h"
#include "class/Donut.h"



int main() {

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Dungeon Crawler Carl");

    //  sf::RenderWindow window(sf::VideoMode({600, 400}), "Dungeon Crawler Carl");

//----------------INITIALISE-------- 

Carl carl; //object 
Donut donut;

//----------------INITIALISE-------- 
carl.Initialize();
donut.Initialize();

// -----------LOAD --------

carl.Load();
donut.Load();
//----------LOAD-------

//----------------UPDATE---------    
//----------------main game loop---------    
    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            }  
        }
        donut.Update();
        carl.Update(donut);
//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        carl.Draw(window);
        donut.Draw(window); 
        window.display();
//----------------DRAW---------  
    }

    return 0;
}