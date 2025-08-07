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
playerSprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));

 //----------LOAD-------
//----------------UPDATE---------    
    while (window.isOpen()) {


        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            
            }
        
            
        }
         sf::Vector2f position = playerSprite.getPosition();

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                // Move right by 10 units
                playerSprite.setTextureRect(sf::IntRect({64, 64 *3}, {64,64}));
                playerSprite.setPosition(position + sf::Vector2f(.05f, 0.f));
                playerSprite.setTextureRect(sf::IntRect({0, 64 *3}, {64,64}));}
            
            
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                // Move left by 10 units
                playerSprite.setPosition(position + sf::Vector2f(-1.f, 0.f));
              
            

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                // Move up by 10 units
                playerSprite.setPosition(position + sf::Vector2f(0.f, -1.f));
              
            

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                // Move down by 10 units
                playerSprite.setPosition(position + sf::Vector2f(0.f, 1.f));
              
            
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