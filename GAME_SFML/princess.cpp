#include "princess.h"
princess::princess(sf::Vector2f position, sf::Texture* princessx) :
    animation(princessx, sf::Vector2u(8, 5), 0.1f)
{

    this->position = position;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position);
    body.setTexture(princessx);


    hitbox.setSize(sf::Vector2f(50.0f, 50.0f));
    hitbox.setOrigin(hitbox.getSize() / 2.f);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(0.f);
    hitbox.setOutlineColor(sf::Color::Blue);


    faceRight = false;
    turn = 0.0f;
}

princess::~princess()
{
}

void princess::update(float deltaTime)
{
    hitbox.setPosition(body.getPosition().x, body.getPosition().y + 30);
    turn += deltaTime;
    if (turn > 4.0f)
    {
        turn = 0.0f;
    }
    if (turn <= 2.0)
    {
        faceRight = false;
    }
    if (turn > 2.0 && turn <= 4.0)
    {
        faceRight = true;
    }
    if (faceRight == true)
    {
        velocity.x = 150;
    }
    if (faceRight == false)
    {
        velocity.x = -150;
    }

    body.move(velocity * deltaTime);
    animation.Updatepenois(1, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
}

void princess::dead()
{
    body.setPosition(3000, 8000);
    hitbox.setPosition(3000, 8000);
}

void princess::re()
{
    turn = 0.0f;
    body.setPosition(position);
    hitbox.setPosition(position);
}

void princess::draw(sf::RenderWindow& window)
{
    window.draw(body);
    window.draw(hitbox);
}
