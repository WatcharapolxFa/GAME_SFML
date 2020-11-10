#include "box.h"
#include "Animation.h"
#include "Player.h"

#include <math.h>
box::box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setOrigin(size.x / 2.f, size.y / 2.f);
	body.setPosition(position);
	body.setTexture(texture);

	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Green);

	row = 0;
}

box::~box()
{
}

void box::Update(float deltaTime, Player player)
{
	
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);

	
}

void box::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::RectangleShape box::getBody() {
	return this->body;
}

