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

	

	row = 0;
	hitbox.setSize(sf::Vector2f(50.0f, 20.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Yellow);
	hitbox.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + 35));
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
	window.draw(hitbox);
}
sf::RectangleShape dimongreen::getBody() {
	return this->body;
}
void dimongreen::pickup()
{
	this->body.setPosition(-20.f, this->body.getPosition().y);
	this->hitbox.setPosition(-20.f, this->body.getPosition().y);
}