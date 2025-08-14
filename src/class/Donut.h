#pragma once

#include <SFML/Graphics.hpp>

class Donut 
{ 



  public:

  int health; 
  sf::Sprite sprite;
  sf::Texture texture;
  
  Donut();
  ~Donut();
  
  sf::RectangleShape boundingRectangle;
  
  

  public:

  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow& window);

};