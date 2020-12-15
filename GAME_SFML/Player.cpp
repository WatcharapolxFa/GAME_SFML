#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	
	
	floorGravity = false;

	row = 0;
	faceRight = true;
	fire = false;
	canJump = false;
	float cooldown = 300;

	body.setSize(sf::Vector2f(60.0f, 98.0f));
	body.setOrigin({ body.getSize().x / 2.0f, 2 * body.getSize().y / 3.0f });


	body.setPosition(91.0f, 1218.0f);
	body.setTexture(texture);

	hitbox.setSize(sf::Vector2f(30.0f, 52.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setPosition(body.getPosition());

	body2.setSize(sf::Vector2f(60.0f, 98.0f));
	body2.setOrigin({ body.getSize().x / 2.0f, 2 * body2.getSize().y / 3.0f });


	body2.setPosition(91.0f, 1218.0f);
	body2.setTexture(texture);

}
Player :: ~Player()
{

}

void Player::Update(float deltaTime,sf::Vector2f direction,float cooldown)
{
	velocity.x = 0.0f;
	fire = false;
	cooldowns = cooldown;
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))// Input by Keyboard.
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))// Input by Keyboard.
	{
		velocity.x += speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)

	{
		canJump = false;
		floorGravity = false; //floorGravity = canFall?

		velocity.y = -sqrtf(2.0f * 500.0f * jumpHeight);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		if (cooldowns <= 200)
		{
			if (faceRight == true)
			{
				velocity.x = 2 * speed;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{

					velocity.x = -2 * speed;
					faceRight = false;
				}
			}
			if (faceRight == false)
			{
				velocity.x = -2 * speed;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					velocity.x = 2 * speed;
					faceRight = true;
				}
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		fire = true;		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		fire = true;
	}

									if (velocity.x == 0.0f && /*velocity.y == 0  &&*/ fire == false)
									{
										row = 0;
									}
									if (velocity.x == 0.0f && /*velocity.y == 0  &&*/ fire == true)
									{
										row = 6;
									}
									/*if (direction.y == 0 && floorGravity==false)
									{
										velocity.y += 981.0f * deltaTime;
							

									}*/
									else if (direction.y < 0.f)
									{
										velocity.y = 0;
									}
									if (velocity.x != 0.0f)
									{
										row = 2;
										if (velocity.x > 0.0f)
											faceRight = true;
										else
											faceRight = false;
									}
									if (velocity.y < 0)
									{
										row = 5;
										
										if (velocity.x < 0.0f)
											faceRight = false;
										if (velocity.x > 0.0f) {
											faceRight = true;
										}
									}
									velocity.y += 981.0f * deltaTime;
	

	
	animation.Update(row, deltaTime, faceRight , fire);
	body.setTextureRect(animation.uvRect);
	hitbox.move(velocity * deltaTime);
	body.setPosition(hitbox.getPosition());
	body2.setTextureRect(animation.uvRect);

}
void Player::backe(sf::RenderWindow& window, sf::Vector2f poses)
{
	body2.setPosition(poses);
	window.draw(body2);

}
void Player::Draw(sf::RenderWindow& window)
{
	
	window.draw(body);
	window.draw(hitbox);
}

void Player::OnCollision(sf::Vector2f direction)
{
	floorGravity = false;
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}

	if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 0.0f;
	}


	if (direction.y < 0.0f)
	{
		//Collision on the bottom.

		velocity.y = 0.0f;
		canJump = true;
		floorGravity = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
		floorGravity = false;
	}
	
 
}

void Player::Warped(sf::RenderWindow& window)
{
	hitbox.setPosition(237.0f, 2891.0f);
	body.setPosition(hitbox.getPosition());
}

void Player::Warped2(sf::RenderWindow& window)
{
	hitbox.setPosition(413.0f, 5280.0f);
	body.setPosition(hitbox.getPosition());
}

void Player::setPosition(float x, float y)
{
	hitbox.setPosition(x, y);
	body.setPosition(hitbox.getPosition());
}
