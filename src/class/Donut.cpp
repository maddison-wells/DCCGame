#include "Donut.h"
#include "Carl.h"
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

void Donut::Load(Carl& carl){

  if(texture.loadFromFile("../img/player/textures/donut_sprite.png"))
{
    std::cout << "donut loaded" << std::endl;
  
}
else{
    std::cout << "donut not loaded" << std::endl;
}


sprite.setTexture(texture);
// sprite.setPosition(sf::Vector2f(100,100)); //not to Carl

// sprite.setPosition(carl.sprite.getPosition());

// sprite.setPosition(sf::Vector2f(100,100)); //not to Carl





sprite.setTextureRect(sf::IntRect({96, 0}, {32, 32}));

}

void Donut::Update(float deltaTime, Carl& carl){
  if(health >0){
 boundingRectangle.setPosition(sprite.getPosition());
}

// sprite.setPosition(carl.sprite.getPosition());
sf::Vector2f carlPos = carl.sprite.getPosition();   // get Carl's position
sf::Vector2f donutPos(carlPos.x + 64.f, carlPos.y);  // offset by 16px on x-axis
sprite.setPosition(donutPos);

}

void Donut::Draw(sf::RenderWindow& window){
  
  if(health > 0){
  window.draw(sprite);
  // window.draw(boundingRectangle);  
  }
}