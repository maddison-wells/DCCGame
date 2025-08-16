#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    Map();
    ~Map();

    void Initialize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);

private:
    static const int NUM_SPRITES = 10;

    sf::Texture tileSheetTexture;
    std::vector<sf::Sprite> sprites;

    int tileWidth;
    int tileHeight;
    int totalTilesX;
    int totalTilesY;
};
