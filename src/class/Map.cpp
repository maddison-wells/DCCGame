#include "Map.h"
#include <iostream>

Map::Map()
    : tileWidth(32), tileHeight(32), totalTilesX(0), totalTilesY(0)
{
    int width = 60;
    int height = 34;
    dummyMap.reserve(width * height);
    for (int i = 0; i < width * height; ++i) {
        dummyMap.push_back(i % 4); 
    }
}

Map::~Map() {}

void Map::Initialize() {}

void Map::DrawMapFromIDs(const std::vector<int>& mapData, int mapWidth, int mapHeight, sf::RenderWindow& window)
{
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int i = x + y * mapWidth;
            int tileID = mapData[i];
            if (tileID >= 0 && tileID < tiles.size()) {
                Tile& t = tiles[tileID];
                if (t.sprite) {
                    t.sprite->setPosition(sf::Vector2f(x * tileWidth, y * tileHeight));
                    window.draw(*t.sprite);
                }
            }
        }
    }
}

void Map::Load()
{
    if (!tileSheetTexture.loadFromFile("../img/world/apartment16x17.png")) {
        std::cout << "Failed to load texture!" << std::endl;
        return;
    }

    totalTilesX = tileSheetTexture.getSize().x / tileWidth;
    totalTilesY = tileSheetTexture.getSize().y / tileHeight;

    tiles.clear();
    tiles.reserve(totalTilesX * totalTilesY);

    for (int y = 0; y < totalTilesY; y++) {
    for (int x = 0; x < totalTilesX; x++) {
        int i = x + y * totalTilesX;

        sf::IntRect rect(
            sf::Vector2i(x * tileWidth, y * tileHeight),
            sf::Vector2i(tileWidth, tileHeight)
        );

        Tile tile(i, &tileSheetTexture, rect);

        if (tile.sprite)
            tile.sprite->setPosition(sf::Vector2f(100.f + x * tileWidth, 100.f + y * tileHeight));

        tiles.emplace_back(std::move(tile));
    }
}

}

void Map::Update(float deltaTime) {}



void Map::Draw(sf::RenderWindow& window)
{
    DrawMapFromIDs(dummyMap, 60, 34, window);
}
