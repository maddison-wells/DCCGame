#include "Map.h"
#include <iostream>

Map::Map() 
    : tileWidth(32), tileHeight(32), totalTilesX(0), totalTilesY(0)
{
    // Pre-allocate memory for sprites, but don't construct them yet
    sprites.reserve(NUM_SPRITES);
}

Map::~Map()
{
}

void Map::Initialize()
{
}

void Map::Load()
{
    if (tileSheetTexture.loadFromFile("../img/world/apartment16x17.png"))
    {
        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;

        sprites.clear(); // reset any old sprites

        for (int i = 0; i < NUM_SPRITES; i++)
        {
            // Construct sprite directly with texture
            sprites.emplace_back(tileSheetTexture);

            sprites[i].setTextureRect(
                sf::IntRect(
                    sf::Vector2i(i * tileWidth, 0), 
                    sf::Vector2i(tileWidth, tileHeight)
                )
            );
            sprites[i].setPosition(sf::Vector2f(100.f + i * tileWidth, 100.f));
        }
    }
    else
    {
        std::cout << "Failed to load texture!" << std::endl;
    }
}

void Map::Update(float deltaTime)
{
}

void Map::Draw(sf::RenderWindow& window) { for (int i = 0; i < NUM_SPRITES; i++) { window.draw(sprites[i]); } }
