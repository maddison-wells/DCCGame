#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

struct Tile {
    int id;
    sf::Texture* texture;
    std::unique_ptr<sf::Sprite> sprite;  // ✅ smart pointer, no default-constructor issue

    Tile(int tid = -1, sf::Texture* tex = nullptr, const sf::IntRect& rect = sf::IntRect())
        : id(tid), texture(tex)
    {
        if (tex) {
            sprite = std::make_unique<sf::Sprite>(*tex, rect);
        }
    }
};
