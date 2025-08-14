#include "Donut.h"
#include <iostream>

Donut::Donut() :

sprite(texture),
health(20)

{}

Donut:: ~Donut()
{}

void Donut::Initialize(){
  boundingRectangle.setFillColor(sf::Color::Transparent);
  boundingRectangle.setOutlineColor(sf::Color::Blue);
  boundingRectangle.setOutlineThickness(1.f);
  boundingRectangle.setSize(sf::Vector2f({64,64}));

}

void Donut::Load(){

  if(texture.loadFromFile("../img/player/textures/donut_sprite.png"))
{
    std::cout << "donut loaded" << std::endl;
  
}
else{
    std::cout << "donut not loaded" << std::endl;
}


sprite.setTexture(texture);
sprite.setPosition(sf::Vector2f(400,100));


sprite.setTextureRect(sf::IntRect({96, 0}, {32, 32}));

}

void Donut::Update(float deltaTime){
  if(health >0){
 boundingRectangle.setPosition(sprite.getPosition());
}
}

void Donut::Draw(sf::RenderWindow& window){
  
  if(health > 0){
  window.draw(sprite);
  window.draw(boundingRectangle);  
  }
}