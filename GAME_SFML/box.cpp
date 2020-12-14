#include "box.h"
#include "Animation.h"
#include "Player.h"
#include <iostream>

#include <math.h>
box::box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->position = position;
	body.setSize(size);
	body.setOrigin(size.x / 2.f, size.y / 2.f);
	body.setPosition(position);
	body.setTexture(texture);

	

	hitbox.setSize(sf::Vector2f(50.0f, 50.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setPosition(body.getPosition().x, body.getPosition().y+20);

	row = 0;
	fire = false;
	canJump = true;
}

box::~box()
{
}

void box::Update(float deltaTime, Player player)
{
 
	hitbox.move( velocity * deltaTime);
	body.setPosition(hitbox.getPosition() - sf::Vector2f(0, 20.f));

	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);

	
}

void box::draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}

void box::re()
{
	body.setPosition(position);
	hitbox.setPosition(position);
}

sf::RectangleShape box::getBody() {
	return this->body;
}

void box::OnCollision(sf::Vector2f direction)
{
	bool coll_X = false , coll_Y = false; 
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 180.0f;
		coll_X = true;
		//std::cout << "l";

	}
 

	if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = -180.0f;
		coll_X = true;
		//std::cout << "r";
	}

	if (!coll_X) {
		velocity.x = 0.0f;
	}


	if (direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
		coll_Y = true;
	}

	if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
		coll_Y = true;
	}

	if (!coll_Y) {
		velocity.y = 50.0f;
	}

}

void box::OnCollision2(sf::Vector2f direction)
{
	bool coll_X = false, coll_Y = false;
	if (direction.x < 0.0f)
	{
		coll_X = true;
	}


	if (direction.x > 0.0f)
	{
		//Collision on the right
		coll_X = true;
	}

	if (coll_X) {
		velocity.x = 0.0f;
	}


	if (direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
		coll_Y = true;
	}

	if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
		coll_Y = true;
	}

	if (!coll_Y) {
		velocity.y = 50.0f;
	}

}