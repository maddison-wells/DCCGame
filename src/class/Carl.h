#pragma once //Only include this header file once per compilation
#include <SFML/Graphics.hpp>
#include <vector>
#include "Donut.h"


class Carl
{
    private:
    // std::vector<sf::RectangleShape> projectiles; 
struct Projectile
{
    sf::RectangleShape shape;
    sf::Vector2f direction;
};

std::vector<Projectile> projectiles;

    float playerSpeed = 2.0f;
    float maxFireRate;
    float fireRateTimer;

    float projectileSpeed = 0.5f;
    // sf::Vector2f projectileDirection;

    sf::RectangleShape boundingRectangle; 

    public:
    sf::Sprite sprite; 
    sf::Texture texture;
  
  public:

    Carl(); //Constructor
    ~Carl();


  void Initialize(); //called once per app start
  void Load(); //called once per app start
  void Update(float deltaTime, Donut& donut); // called once per frame
  void Draw(sf::RenderWindow& window); // called once per frame

};