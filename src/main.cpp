// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

int main() {

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Dungeon Crawler Carl");

 //----------------INITIALISE-------- 
 
 // -----------LOAD --------

sf::Texture carlTexture;

if(carlTexture.loadFromFile("../img/player/textures/carl_sheet.png"))
{
    std::cout << "loaded" << std::endl;
  
}
else{
    std::cout << "not loaded" << std::endl;
}

sf::Sprite carlSprite(carlTexture);
carlSprite.setTexture(carlTexture);

// int Xindex = 0;
// int Yindex = 0;
// {x, Y}, {Width, Height}
carlSprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));

sf::Texture donutTexture;

if(donutTexture.loadFromFile("../img/player/textures/donut_sprite.png"))
{
    std::cout << "donut loaded" << std::endl;
  
}
else{
    std::cout << "donut not loaded" << std::endl;
}

sf::Sprite donutSprite(donutTexture);
donutSprite.setTexture(donutTexture);
donutSprite.setPosition(sf::Vector2f(400,100));


donutSprite.setTextureRect(sf::IntRect({96, 0}, {32, 32}));

 //----------LOAD-------
//----------------UPDATE---------    
    while (window.isOpen()) {


        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            
            }
        
            
        }
         sf::Vector2f position = carlSprite.getPosition();

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                carlSprite.setTextureRect(sf::IntRect({64, 64 *3}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(.05f, 0.f));}
            
            
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                
                
                carlSprite.setTextureRect(sf::IntRect({0, 64}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(-.05f, 0.f));

             }
            

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
             {  carlSprite.setTextureRect(sf::IntRect({0, 0}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(0.f, -.05f));
              
             }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                carlSprite.setTextureRect(sf::IntRect({0, 128}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(0.f, .05f));
             }
            
//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        // drawing code goes here, shouldnt update here
        window.draw(carlSprite);
        window.draw(donutSprite);
        window.display();
//----------------DRAW---------  
    }

    return 0;
}