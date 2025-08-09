#include "Carl.h"
#include <iostream>


// Carl::Carl() {

// }

void Carl::Draw()
{


}

void Carl::Initialize()
{

}

void Carl::Load(){
if(texture.loadFromFile("../img/player/textures/carl_sheet.png"))
{
    std::cout << "loaded" << std::endl;
  
}
else{
    std::cout << "not loaded" << std::endl;
}


sprite.setTexture(texture);

sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));

sprite.setPosition({100,700});
}

void Carl::Update(){

  sf::Vector2f position = sprite.getPosition();

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                sprite.setTextureRect(sf::IntRect({64, 64 *3}, {64,64}));
                sprite.setPosition(position + sf::Vector2f(.5f, 0.f));}
            
            
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                
                
                sprite.setTextureRect(sf::IntRect({0, 64}, {64,64}));
                sprite.setPosition(position + sf::Vector2f(-.5f, 0.f));

             }
            

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
             {  sprite.setTextureRect(sf::IntRect({0, 0}, {64,64}));
                sprite.setPosition(position + sf::Vector2f(0.f, -.5f));
              
             }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                sprite.setTextureRect(sf::IntRect({0, 128}, {64,64}));
                sprite.setPosition(position + sf::Vector2f(0.f, .5f));
             }
    

}