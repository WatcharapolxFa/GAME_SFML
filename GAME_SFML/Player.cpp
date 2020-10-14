#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,float jumpHeight):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;

	row = 0;
	faceRight = true;



	body.setSize(sf::Vector2f(60.0f, 98.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(5.0f, 100.0f);
	body.setTexture(texture);
}
Player :: ~Player()
{

}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))// Input by Keyboard.
	{
		velocity.y += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))// Input by Keyboard.
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))// Input by Keyboard.
	{
		velocity.x += speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump)

	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		cout << "Hello E";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		std::cout << "Hello Q";
	}


	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 4;
	}
	
	else
	{
		row = 2;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
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
		velocity.x = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}

}
