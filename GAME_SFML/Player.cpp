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

	this->hitbox = new hitboxComponent(sf::Vector2f(10, 30), sf::Vector2f(40, 50));

	body.setSize(sf::Vector2f(60.0f, 98.0f));
	body.setOrigin({ body.getSize().x / 2.0f,body.getSize().y / 2.0f });
	
	body.setPosition(100.0f, 100.0f);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&canJump)

	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 500.0f * jumpHeight);
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
	hitbox->move(velocity * deltaTime);
	this->body.setPosition(this->hitbox->getPosition().x, this->hitbox->getPosition().y );

}
void Player::Draw(sf::RenderWindow& window)
{
	hitbox->Draw(&window);
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
