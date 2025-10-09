#include "Donut.h"
#include "Carl.h"
#include <iostream>
#include <vector>

Donut::Donut() :


sprite(texture),
health(20),
cFrame(0),
tFrames(3),
fDelay(80.0f)


{}

Donut:: ~Donut()
{}

void Donut::setAnimationFrame(sf::Sprite& sprite, int frameIndex, int frameWidth, int frameHeight, int row = 0) {
  int x = frameIndex * frameWidth;
  int y = row * frameHeight;
  sprite.setTextureRect(sf::IntRect({x,y}, {frameWidth, frameHeight}));
}

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

sprite.setPosition(carl.sprite.getPosition());

// sprite.setPosition(sf::Vector2f(100,100)); //not to Carl





sprite.setTextureRect(sf::IntRect({96, 0}, {32, 32}));

}

void Donut::Update(float deltaTime, Carl& carl){
  if(health >0){
 boundingRectangle.setPosition(sprite.getPosition());
}

// sprite.setPosition(carl.sprite.getPosition());
sf::Vector2f carlPos = carl.sprite.getPosition();   // get Carl's position
sf::Vector2f donutPos(carlPos.x - 10.f, carlPos.y + 40.f);  // offset by 16px on x-axis
sprite.setPosition(donutPos);


sf::Vector2f position = sprite.getPosition();

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
  tAccumulator += deltaTime;
  if(tAccumulator >= fDelay){
    cFrame = (cFrame + 1) % tFrames;
    setAnimationFrame(sprite, cFrame,32, 32, 0);
    tAccumulator = 0.0f;
  }

  sprite.setPosition(position + sf::Vector2f(1.f, 0.f) * pSpeed * deltaTime);
}


if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
  tAccumulator += deltaTime;
  if(tAccumulator >= fDelay){
    cFrame = (cFrame + 1) % tFrames;
    setAnimationFrame(sprite, cFrame,32, 32, 3);
    tAccumulator = 0.0f;
  }

  sprite.setPosition(position + sf::Vector2f(-1.f, 0.f) * pSpeed * deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
  tAccumulator += deltaTime;
  if(tAccumulator >= fDelay){
    cFrame = (cFrame + 1) % tFrames;
    setAnimationFrame(sprite, cFrame,32, 32, 2);
    tAccumulator = 0.0f;
  }

  sprite.setPosition(position + sf::Vector2f(0.f, -1.f) * pSpeed * deltaTime);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
  tAccumulator += deltaTime;
  if(tAccumulator >= fDelay){
    cFrame = (cFrame + 1) % tFrames;
    setAnimationFrame(sprite, cFrame,32, 32, 1);
    tAccumulator = 0.0f;
  }

  sprite.setPosition(position + sf::Vector2f(0.f, 1.f) * pSpeed * deltaTime);
}

}

void Donut::Draw(sf::RenderWindow& window){
  
  if(health > 0){
  window.draw(sprite);
  // window.draw(boundingRectangle);  
  }
}