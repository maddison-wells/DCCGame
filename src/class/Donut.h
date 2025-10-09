#pragma once


#include <SFML/Graphics.hpp>
#include <vector>

class Carl;

class Donut 
{ 



  public:

  int health; 
  sf::Sprite sprite;
  sf::Texture texture;
  int cFrame;
  float tAccumulator; 
  const int tFrames;
  const float fDelay; 
  float pSpeed = .30f;

  
  Donut();
  ~Donut();
  
  sf::RectangleShape boundingRectangle;
  
  

  public:

  void Initialize();
  void Load(Carl& carl);
  void Update(float deltaTime, Carl& carl);
  void Draw(sf::RenderWindow& window);

  void setAnimationFrame(sf::Sprite& sprite, int frameIndex, int frameWidth, int frameHeight, int row);


};