#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <iostream>
#include "Collider.h"
using namespace std;

class Bullet
{
public:
    Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos, sf::Vector2f size, float cool);
    ~Bullet();
    void updateL(float deltaTime);
    void updateR(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isAvaliable();
    void attackR(sf::Vector2f pos);
    void attackL(sf::Vector2f pos);
    void OnCollision(sf::Vector2f direction);
    void SetPosition(sf::Vector2f pos);
    float cooldown(float deltaTime, int check);

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
private:
    Animation animation;
    float speed;
    sf::RectangleShape body;
    unsigned int row;
    sf::Vector2f velocity;
    float cooling;
    float cool;

    bool isAva = true;
};
