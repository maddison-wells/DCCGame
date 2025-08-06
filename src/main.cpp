// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

int main() {

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Dungeon Crawler Carl");

 //----------------INITIALISE-------- 
 
 // -----------LOAD --------

sf::Texture playerTexture;

if(playerTexture.loadFromFile("../img/player/textures/sprite_sheet.png"))
{
    std::cout << "loaded" << std::endl;
  
}
else{
    std::cout << "not loaded" << std::endl;
}

sf::Sprite playerSprite(playerTexture);
playerSprite.setTexture(playerTexture);

int Xindex = 0;
int Yindex = 0;
// {x, Y}, {Width, Height}
playerSprite.setTextureRect(sf::IntRect({Xindex * 64, Yindex * 64}, {64, 64}));

 //----------LOAD-------
//----------------UPDATE---------    
    while (window.isOpen()) {


        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            // make sprite move
            }
            // get current position
           else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){

               
                sf::Vector2f position = playerSprite.getPosition();

                // Move right by 10 units
                playerSprite.setPosition(position + sf::Vector2f(10.f, 0.f));
              
            }
            
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){

               
                sf::Vector2f position = playerSprite.getPosition();

                // Move left by 10 units
                playerSprite.setPosition(position + sf::Vector2f(-10.f, 0.f));
              
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){

               
                sf::Vector2f position = playerSprite.getPosition();

                // Move up by 10 units
                playerSprite.setPosition(position + sf::Vector2f(0.f, -10.f));
              
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){

               
                sf::Vector2f position = playerSprite.getPosition();

                // Move down by 10 units
                playerSprite.setPosition(position + sf::Vector2f(0.f, 10.f));
              
            }
            
            
        }

//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        // drawing code goes here, shouldnt update here
        window.draw(playerSprite);
        window.display();
//----------------DRAW---------  
    }

    return 0;
}