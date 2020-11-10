#pragma once
#include "item.h"
#include "Animation.h"
#include <math.h>
item::item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);
	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Green);

	row = 0;
}

item::~item()
{
}

void item::Update(float deltaTime, Player player)
{
	animation.Updatewater(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void item::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
sf::RectangleShape item::getBody() {
	return this->body;
}
