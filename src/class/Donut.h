#pragma once


#include <SFML/Graphics.hpp>

class Carl;

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
  void Load(Carl& carl);
  void Update(float deltaTime, Carl& carl);
  void Draw(sf::RenderWindow& window);

};