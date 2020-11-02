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
}
Bullet::~Bullet()
{
}

void Bullet::updateR(float deltaTime)
{
    velocity.y = 0;
    velocity.x = speed;

    body.move(velocity * deltaTime);
    animation.updateBu(row, deltaTime, true);
    body.setTextureRect(animation.uvRect);
}

void Bullet::updateL(float deltaTime)
{
    velocity.y = 0;
    velocity.x = speed;

    body.move(-(velocity * deltaTime));
    animation.updateBu(row, deltaTime, false);
    body.setTextureRect(animation.uvRect);
}

void Bullet::attackR(sf::Vector2f pos)
{
    if (isAva == true)
    {
        body.setPosition(pos.x + 50.0f, pos.y); //position bullet R
        isAva = false;
    }
}

void Bullet::attackL(sf::Vector2f pos)
{
    if (isAva == true)
    {
        body.setPosition(pos.x - 50.0f, pos.y);//position bullet L
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
}

void Bullet::SetPosition(sf::Vector2f pos)
{
    body.setPosition(pos.x, pos.y + 720.0f);
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