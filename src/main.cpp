// // make
// // ./dcc-app 

#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include<vector>
#include<math.h>

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

std::vector<sf::RectangleShape> projectiles; //plural

// sf:: RectangleShape projectile(sf::Vector2f({10,5}));
// projectile.setPosition(sf::Vector2f({50,50})); //dont set position in loop, only set once

float projectileSpeed = 0.5f;
sf::Vector2f projectileDirection;



 // -----------LOAD --------

sf::Texture carlTexture;

if(carlTexture.loadFromFile("../img/player/textures/carl_sheet.png"))
{
    std::cout << "loaded" << std::endl;
  
}
else{
    std::cout << "not loaded" << std::endl;
}

sf::Sprite carlSprite(carlTexture);
carlSprite.setTexture(carlTexture);


// int Xindex = 0;
// int Yindex = 0;
// {x, Y}, {Width, Height}
carlSprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));

carlSprite.setPosition({100,700});

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

//  projectile.setPosition(carlSprite.getPosition());

//  //----projectile direction

//  sf::Vector2f projectileDirection = donutSprite.getPosition() - projectile.getPosition();

//  projectileDirection = NormalizeVector(projectileDirection);


//----------------UPDATE---------    


//----------------main game loop---------    
    while (window.isOpen()) {


        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) { 
                window.close();
            
            }
        
    

            
        }

        // projectile.setPosition(projectile.getPosition() + projectileDirection * projectileSpeed);

         sf::Vector2f position = carlSprite.getPosition();

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
                carlSprite.setTextureRect(sf::IntRect({64, 64 *3}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(.5f, 0.f));}
            
            
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                
                
                carlSprite.setTextureRect(sf::IntRect({0, 64}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(-.5f, 0.f));

             }
            

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
             {  carlSprite.setTextureRect(sf::IntRect({0, 0}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(0.f, -.5f));
              
             }

             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
                carlSprite.setTextureRect(sf::IntRect({0, 128}, {64,64}));
                carlSprite.setPosition(position + sf::Vector2f(0.f, .5f));
             }
    

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            projectiles.push_back(sf::RectangleShape(sf::Vector2f({50,25}))); //add to vector

            int i = projectiles.size() -1;
            
            projectiles[i].setPosition(carlSprite.getPosition());
        }

        for(size_t i = 0; i < projectiles.size(); i++)
        {
            projectileDirection = donutSprite.getPosition() - projectiles[i].getPosition();
            projectileDirection = NormalizeVector(projectileDirection);
            projectiles[i].setPosition(projectiles[i].getPosition()+ projectileDirection * projectileSpeed);
        }


//----------------UPDATE---------  

//----------------DRAW---------  
        window.clear(sf::Color::Black);
        // drawing code goes here, shouldn't update here
        window.draw(carlSprite);
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