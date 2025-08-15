#pragma once
#include <SFML/Graphics.hpp>

class Map {


    sf::Texture tileSheetTexture;
    sf::Sprite sprite;
    
public:
  Map();
  ~Map(); 
 void Initialize();
 void Load ();
 void Update(float deltaTime);
 void Draw(sf::RenderWindow& window);

};