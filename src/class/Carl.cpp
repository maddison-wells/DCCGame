#include "Carl.h"
#include <iostream>
#include "Math.h"


void Carl::Draw(sf::RenderWindow& window)
{
   window.draw(sprite);
   for (size_t i = 0; i <projectiles.size(); i ++){
            window.draw(projectiles[i]);
        }
   
   window.draw(boundingRectangle);     
}

void Carl::Initialize()
{ 
  boundingRectangle.setFillColor(sf::Color::Transparent);
  boundingRectangle.setOutlineColor(sf::Color::Red);
  boundingRectangle.setOutlineThickness(1.f);
  boundingRectangle.setSize(sf::Vector2f({64,64}));
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

void Carl::Update(Donut& donut){

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
    
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            projectiles.push_back(sf::RectangleShape(sf::Vector2f({50,25}))); //add to vector

            int i = projectiles.size() -1;
            
            projectiles[i].setPosition(sprite.getPosition());
        }

        for(size_t i = 0; i < projectiles.size(); i++)
        {
            projectileDirection = donut.sprite.getPosition() - projectiles[i].getPosition();
            projectileDirection = Math::NormalizeVector(projectileDirection);
            projectiles[i].setPosition(projectiles[i].getPosition()+ projectileDirection * projectileSpeed);
        }

        boundingRectangle.setPosition(sprite.getPosition());

      if(Math::CheckRectCollision(sprite.getGlobalBounds(), donut.sprite.getGlobalBounds())){
        std::cout<<"collison"<< std::endl;
      }
}