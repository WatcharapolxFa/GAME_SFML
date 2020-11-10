#include "dimongreen.h"
#include "Animation.h"

#include <math.h>
dimongreen::dimongreen(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Yellow);

	row = 0;
}

dimongreen::~dimongreen()
{
}

void dimongreen::Update(float deltaTime, Player player)
{
	animation.Updatewater(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void dimongreen::draw(sf::RenderWindow& window)
{
	window.draw(body);
}
sf::RectangleShape dimongreen::getBody() {
	return this->body;
}