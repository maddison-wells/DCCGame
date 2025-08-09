// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include<vector>
#include<math.h>
#include "class/Carl.h"

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    sf::Vector2f normalizedVector;

   normalizedVector.x = vector.x /m;
   normalizedVector.y = vector.y /m;

   return normalizedVector;


}

int main() {


    

//----------------INITIALISE---------    
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Dungeon Crawler Carl");

    //  sf::RenderWindow window(sf::VideoMode({600, 400}), "Dungeon Crawler Carl");

 //----------------INITIALISE-------- 

Carl carl; //object from player class
carl.Initialize();
carl.Load();

std::vector<sf::RectangleShape> projectiles; //plural

// sf:: RectangleShape projectile(sf::Vector2f({10,5}));
// projectile.setPosition(sf::Vector2f({50,50})); //dont set position in loop, only set once

float projectileSpeed = 0.5f;
sf::Vector2f projectileDirection;


 // -----------LOAD --------



sf::Texture donutTexture;

if(donutTexture.loadFromFile("../img/player/textures/donut_sprite.png"))
{
    std::cout << "donut loaded" << std::endl;
  
}
else{
    std::cout << "donut not loaded" << std::endl;
}

sf::Sprite donutSprite(donutTexture);
donutSprite.setTexture(donutTexture);
donutSprite.setPosition(sf::Vector2f(400,100));


donutSprite.setTextureRect(sf::IntRect({96, 0}, {32, 32}));

 //----------LOAD-------




//----------------UPDATE---------    


//----------------main game loop---------    
    while (window.isOpen()) {


        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            
            }  
        }
        carl.Update();

     
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            projectiles.push_back(sf::RectangleShape(sf::Vector2f({50,25}))); //add to vector

            int i = projectiles.size() -1;
            
            projectiles[i].setPosition(carl.sprite.getPosition());
        }

        for(size_t i = 0; i < projectiles.size(); i++)
        {
            projectileDirection = donutSprite.getPosition() - projectiles[i].getPosition();
            projectileDirection = NormalizeVector(projectileDirection);
            projectiles[i].setPosition(projectiles[i].getPosition()+ projectileDirection * projectileSpeed);
        }

carl.Update();

//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        // drawing code goes here, shouldn't update here
        carl.Draw();
        window.draw(carl.sprite);
        window.draw(donutSprite);
        for (size_t i = 0; i <projectiles.size(); i ++){
            window.draw(projectiles[i]);
        }
        // window.draw(projectile);
        window.display();
//----------------DRAW---------  
    }

    return 0;
}