#pragma once

#include <SFML/Graphics.hpp>

class Donut 
{ 
  public:

  sf::Sprite sprite;
  sf::Texture texture;
  Donut() : sprite(texture){};

  public:

  void Initialize();
  void Load();
  void Update();
  void Draw(sf::RenderWindow& window);

};