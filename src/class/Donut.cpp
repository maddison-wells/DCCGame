#include "Donut.h"
#include <iostream>

void Donut::Initialize(){

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

void Donut::Update(){

}

void Donut::Draw(sf::RenderWindow& window){
  window.draw(sprite);
}