#include "Player.h"
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
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
	sf::Vector2f movement(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= speed * deltaTime;
	}*/
	if (movement.x == 0.0f)
	{
		row = 4;
	}
	
	else
	{
		row = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
