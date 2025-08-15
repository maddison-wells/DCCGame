#include "Map.h"
#include <iostream>

Map::Map() :

sprite(tileSheetTexture)

{
}

Map::~Map()
{

}

void Map::Initialize()
{

}
void Map::Load()
{

  if (tileSheetTexture.loadFromFile("../img/world/apartment.png"))
{
    std::cout << "tile loaded" << std::endl;
  
}
else{
    std::cout << "tile not loaded" << std::endl;
}

  sprite.setTexture(tileSheetTexture);
  sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));


}
void Map::Update(float deltaTime)
{

}
void Map::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
