#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos, sf::Vector2f size, float cool) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->cool = cool;
    row = 0;
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos);
    body.setTexture(texture);
    bool faceleft = false;
    cooling = 10.0f; //time is cooldown

    hitbox.setSize(size);
    hitbox.setOrigin(hitbox.getSize() / 2.f);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1.f);
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setPosition(body.getPosition().x, body.getPosition().y );
   
}
Bullet::~Bullet()
{
}

void Bullet::updateR(float deltaTime)
{
    hitbox.setPosition(body.getPosition().x, body.getPosition().y);
    velocity.y = 0;
    velocity.x = speed;
       
    body.move(velocity * deltaTime);
    animation.updateBu(row, deltaTime, true);
    body.setTextureRect(animation.uvRect);
    hitbox.setPosition(body.getPosition().x, body.getPosition().y );
    
}

void Bullet::updateL(float deltaTime)
{
    hitbox.setPosition(body.getPosition().x, body.getPosition().y);
    velocity.y = 0;
    velocity.x = speed;

    body.move(-(velocity * deltaTime));
    animation.updateBu(row, deltaTime, false);
    body.setTextureRect(animation.uvRect);
    hitbox.setPosition(body.getPosition().x, body.getPosition().y );
}

void Bullet::attackR(sf::Vector2f pos)
{
    if (isAva == true)
    {
        body.setPosition(pos.x + 20.0f, pos.y); //position bullet R
        isAva = false;
    }
}

void Bullet::attackL(sf::Vector2f pos)
{
    if (isAva == true)
    {
        body.setPosition(pos.x - 20.0f, pos.y);//position bullet L
        isAva = false;
    }
}

bool Bullet::isAvaliable() // status bullet
{
    isAva = true;
    return isAva;
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(body);
    window.draw(hitbox);
}

void Bullet::SetPosition()
{
    body.setPosition(-5000,-5000);
    hitbox.setPosition(body.getPosition().x, body.getPosition().y);
}

void Bullet::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        //left
        velocity.x = 0.0f;
        isAva = true;
    }
    else if (direction.x > 0.0f)
    {
        //right
        velocity.x = 0.0f;
        isAva = true;
    }
    if (direction.y < 0.0f)
    {
        //bottom
        velocity.y = 0.0f;
    }
    else if (direction.y > 0.0f)
    {
        //top
        velocity.y = 0.0f;
    }
}

float Bullet::cooldown(float deltaTime, int check)
{
    if (cooling < cool) // cooling begin is time //cool 
    {
        cooling += deltaTime;
    }
    if (cooling >= cool)
    {
        if (check != 0)// cheek bullet 
        {
            cooling = 0.0f;
        }
    }
    return cooling;
}