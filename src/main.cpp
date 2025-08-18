// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include "class/Carl.h"
#include "class/Donut.h"
#include "class/Map.h"
#include "class/MapLoader.h"



int main() {

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Dungeon Crawler Carl");

    //  sf::RenderWindow window(sf::VideoMode({600, 400}), "Dungeon Crawler Carl");

    window.setFramerateLimit(240);

//----------------INITIALISE-------- 

sf::Font font("../Assets/Fonts/Arial.ttf");
sf::Text frameRateText(font);


Carl carl; //object 
Donut donut;
Map map;



//----------------INITIALISE / Load-------- 
map.Initialize();
map.Load();

donut.Initialize();
donut.Load();

carl.Initialize();
carl.Load();



sf::Clock clock;
//----------LOAD-------

//----------------UPDATE---------    
//----------------main game loop---------    
    while (window.isOpen()) {

        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();
        // std::cout << deltaTime << std::endl;

        frameRateText.setString(std::to_string(1000.0f/deltaTime));

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            }  
        }  

        map.Update(deltaTime);
        carl.Update(deltaTime, donut);
        donut.Update(deltaTime);
//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear();
        map.Draw(window);
        carl.Draw(window);
        donut.Draw(window); 
        // window.draw(frameRateText);
        window.display();
//----------------DRAW---------  
    
    }

    return 0;
}