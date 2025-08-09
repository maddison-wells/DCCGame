#pragma once //Only include this header file once per compilation
#include <SFML/Graphics.hpp>


class Carl
{
 
    public:
    sf::Sprite sprite; //needed for projectile
     sf::Texture texture;
    Carl() : sprite(texture){}; //Constructor
    

  public:

  void Initialize(); //called once per app start
  void Load(); //called once per app start
  void Update(); // called once per frame
  void Draw(); // called once per frame

};