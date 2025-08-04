// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>

int main() {

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Dungeon Crawler Carl");
    sf::CircleShape shape(50.0f); //f is floating point
    shape.setPosition(sf::Vector2f(100,100));
    //----------------INITIALISE---------    

    while (window.isOpen()) {
//----------------UPDATE---------    

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            }
        }

//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        // drawing code goes here, shouldnt update here
        window.draw(shape);
        window.display();
//----------------DRAW---------  
    }

    return 0;
}
