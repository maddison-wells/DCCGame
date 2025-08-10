#pragma once //Only include this header file once per compilation
#include <SFML/Graphics.hpp>
#include <vector>
#include "Donut.h"


class Carl
{
    private:
    std::vector<sf::RectangleShape> projectiles; //plural


    float projectileSpeed = 0.5f;
    sf::Vector2f projectileDirection;

    public:
    sf::Sprite sprite; 
    sf::Texture texture;
    Carl() : sprite(texture){}; //Constructor
    

  public:

  void Initialize(); //called once per app start
  void Load(); //called once per app start
  void Update(Donut& donut); // called once per frame
  void Draw(sf::RenderWindow& window); // called once per frame

};