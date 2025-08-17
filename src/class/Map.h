#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Map {
public:
    Map();
    ~Map();

    void DrawMapFromIDs(const std::vector<int>& mapData, int mapWidth, int mapHeight, sf::RenderWindow& window);


    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    

private:
    // static const int NUM_SPRITES = 10;

    sf::Texture tileSheetTexture;
    std::vector<Tile> tiles;
    std::vector<int> dummyMap;
        
    // std::vector<sf::Sprite> sprites;

    // Tile *tiles;

    int tileWidth;
    int tileHeight;
    int totalTilesX;
    int totalTilesY;

    

};
