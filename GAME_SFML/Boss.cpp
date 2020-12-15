#include "Boss.h"
#include"HitboxComponent.h"

Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
    animation(texture, imageCount, switchTime)
{
	hp = 10;
	faceRight = true;
    main = 0.0f;
    mainn = 0.0f;
    body.setSize(sf::Vector2f(256.0f, 300.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(200.0f, 7100.0f);//200 - 1600
    body.setTexture(texture);

    hitbox.setSize(sf::Vector2f(160.0f, 200.0f));
    hitbox.setOrigin(hitbox.getSize() / 2.f);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1.f);
    hitbox.setOutlineColor(sf::Color::Blue);
    hitbox.setPosition(body.getPosition());

}

Boss::~Boss()
{
}

void Boss::Update(float deltaTime,float px)
{
	mainn += deltaTime;
    main = mainn ;
    if (hp >= 1)
    {
        main += deltaTime;
        if (main < 0.1f)
        {
            body.setPosition(200.0f, 7100.0f);
        }
        if (main <= 3.0f)
        {
            faceRight = true;
            velocity.y = 0.0;
            velocity.x = 200.0;
        }
        if (main > 3.0f && main < 3.1f)
        {
            body.setPosition(1600.0f, 7100.0f);
        }
        if (main > 3.0f && main <= 6.0f)
        {
            faceRight = false;
            velocity.y = 0.0;
            velocity.x = -200.0;
        }  
        if (main > 6.0f && main < 6.1f)
        {
            body.setPosition(px, 6500.0f);
        }
        if (main > 6.0f && main <= 9.0f)
        {
            velocity.y = 400.0;
            velocity.x = 0.0;
        }
        if (main > 9.0f && main <= 12.0f)
        {
            faceRight = true;
            velocity.y = 0.0;
            velocity.x = 0.0;
            body.setPosition(200.0f, 7100.0f);
        }
        if (main > 12.0f && main <= 15.0f)
        {
            faceRight = false;
            velocity.y = 0.0;
            velocity.x = 0.0;
            body.setPosition(1600.0f, 7100.0f);
        }
        if (mainn > 15.0f)
        {
            mainn = 0.0f;
        }
    }
    body.move(velocity * deltaTime);
    animation.updateBu(0, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    hitbox.setPosition(body.getPosition().x,body.getPosition().y + 50);
}

void Boss::draw(sf::RenderWindow& window)
{
    window.draw(body);
    window.draw(hitbox);
}

void Boss::dead()
{
    body.setPosition(-5000,-5000);
    main = 0.0f;
}

void Boss::damaged(int dmg)
{
    for (int i = 0; i < dmg; i++)
    {
        if (hp > 0)
        {
            hp = hp - 1;
        }
    }
}

void Boss::re()
{
    hp = 10;
    mainn = 0.0f;
}


