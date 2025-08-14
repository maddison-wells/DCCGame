#include "Carl.h"
#include <iostream>
#include "Math.h"
#include <vector>

Carl::Carl() :


    sprite(texture),
    maxFireRate(1000),
    fireRateTimer(0)
 {}
  
Carl:: ~Carl()
{

}

void Carl::Draw(sf::RenderWindow& window)
{
   window.draw(sprite);
   for (size_t i = 0; i <projectiles.size(); i ++){
            window.draw(projectiles[i].shape);

        }
   
   window.draw(boundingRectangle);     
}

void Carl::Initialize()
{ 
  boundingRectangle.setFillColor(sf::Color::Transparent);
  boundingRectangle.setOutlineColor(sf::Color::Red);
  boundingRectangle.setOutlineThickness(1.f);
  boundingRectangle.setSize(sf::Vector2f({64,64}));
}

void Carl::Load(){
if(texture.loadFromFile("../img/player/textures/carl_sheet.png"))
{
    std::cout << "loaded" << std::endl;
  
}
else{
    std::cout << "not loaded" << std::endl;
}


sprite.setTexture(texture);

sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));

sprite.setPosition({100,700});
}

void Carl::Update(float deltaTime, Donut& donut)
{
    // Timer for fire rate
    fireRateTimer += deltaTime;

    // --- Player movement ---
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        sprite.setTextureRect(sf::IntRect({64, 64 * 3}, {64, 64}));
        sprite.setPosition(position + sf::Vector2f(1.f, 0.f) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        sprite.setTextureRect(sf::IntRect({0, 64}, {64, 64}));
        sprite.setPosition(position + sf::Vector2f(-.5f, 0.f) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        sprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
        sprite.setPosition(position + sf::Vector2f(0.f, -.5f) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));
        sprite.setPosition(position + sf::Vector2f(0.f, .5f) * playerSpeed * deltaTime);
    }

    // --- Fire projectile ---
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        Projectile p;
        p.shape.setSize(sf::Vector2f(50, 25));
        p.shape.setPosition(sprite.getPosition());

        // Calculate initial direction toward Donut
        sf::Vector2f diff = donut.sprite.getPosition() - p.shape.getPosition();
        if (Math::VectorLength(diff) > 0.001f) {
            p.direction = Math::NormalizeVector(diff);
        } else {
            p.direction = {0.f, 0.f};
        }

        projectiles.push_back(p);
        fireRateTimer = 0;
    }

    // --- Move projectiles ---
    for (auto& proj : projectiles) {
        proj.shape.setPosition(
            proj.shape.getPosition() + proj.direction * projectileSpeed * deltaTime);
    }

    // --- Collision detection ---
    for (int i = projectiles.size() - 1; i >= 0; --i)
    {
        if(donut.health >=0){
        if (Math::CheckRectCollision(projectiles[i].shape.getGlobalBounds(),
                                     donut.sprite.getGlobalBounds()))
        {
            std::cout << "collision" << std::endl;
            projectiles.erase(projectiles.begin() + i);

            donut.health -= 10;
            std::cout << donut.health << std::endl;
        }
    }
    }

    // Update bounding box
    boundingRectangle.setPosition(sprite.getPosition());
}
