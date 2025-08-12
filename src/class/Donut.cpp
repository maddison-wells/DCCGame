#include "Donut.h"
#include <iostream>

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
 boundingRectangle.setPosition(sprite.getPosition());
}

void Donut::Draw(sf::RenderWindow& window){
  window.draw(sprite);
  window.draw(boundingRectangle);  
}