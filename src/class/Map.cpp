#include "Map.h"
#include <iostream>

Map::Map() 
    : tileWidth(32), tileHeight(32), totalTilesX(0), totalTilesY(0)
{
    // Pre-allocate memory for sprites, but don't construct them yet
    // sprites.reserve(NUM_SPRITES);
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

        tiles.clear();
        tiles.reserve(totalTilesX * totalTilesY);

        for (size_t y = 0; y < totalTilesY; y++)
        {
            for (size_t x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;

                sf::IntRect rect(
                    sf::Vector2i(x * tileWidth, y * tileHeight),
                    sf::Vector2i(tileWidth, tileHeight)
                );

                Tile tile(i, &tileSheetTexture, rect);

                // set position after sprite exists
                if (tile.sprite) {
                    tile.sprite->setPosition(
                        sf::Vector2f(100.f + x * tileWidth, 100.f + y * tileHeight)
                    );
                }

                tiles.emplace_back(std::move(tile));
            }
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

void Map::Draw(sf::RenderWindow& window)
{
    for (auto& tile : tiles)
    {
        if (tile.sprite) {
            window.draw(*tile.sprite);  
        }
    }
}
