#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;

	row = 0;
	faceRight = true;
	fire = false;
	canJump = false;
	body.setSize(sf::Vector2f(60.0f, 98.0f));
	body.setOrigin({ body.getSize().x / 2.0f,body.getSize().y / 2.0f });

	body.setPosition(91.0f, 1218.0f);
	body.setTexture(texture);
}
Player :: ~Player()
{

}

void Player::Update(float deltaTime,sf::Vector2f direction)
{
	velocity.x = 0.0f;
	fire = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))// Input by Keyboard.
	{
		canJump = false;

		velocity.y = +sqrtf(2.0f * 500.0f * jumpHeight);
	}

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

		velocity.y = -sqrtf(2.0f * 500.0f * jumpHeight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		fire = true;		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		fire = true;
	}

									if (velocity.x == 0.0f && velocity.y == 0 && fire == false)
									{
										row = 0;
									}
									if (velocity.x == 0.0f && velocity.y == 0 && fire == true)
									{
										row = 6;
									}
									if (direction.y >= 0 )
									{
										velocity.y += 981.0f * deltaTime;

									}
									if (direction.y == -1)
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
	

	
	animation.Update(row, deltaTime, faceRight , fire);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
	
}
void Player::Draw(sf::RenderWindow& window)
{
	
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
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
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
	

}
void Player::Warped(sf::RenderWindow& window)
{
	body.setPosition(237.0f, 2891.0f);
}

void Player::Warped2(sf::RenderWindow& window)
{
	body.setPosition(450.0f, 5000.0f);
}

void Player::setPosition(float x, float y)
{
	body.setPosition(x, y);
}
