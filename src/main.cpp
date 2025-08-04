// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Dungeon Crawler Carl");

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            }
        }

        window.clear(sf::Color::Yellow);
        // drawing code goes here, shouldnt update here
        
        window.display();
    }

    return 0;
}
