#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,float jumpHeight):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(120.0f, 196.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(10.0f, 500.0f);
	body.setTexture(texture);
}
Player :: ~Player()
{

}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.8f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&canJump)

	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
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
		velocity.x = 00.f;
	}

	if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 00.f;
	}


	if (direction.y > 0.0f)
	{
		//Collision on the bottom.
		velocity.x = 00.f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 00.f;
	}

}
