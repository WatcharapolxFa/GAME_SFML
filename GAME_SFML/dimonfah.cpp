#include "dimonfah.h"
#include "Animation.h"

#include <math.h>
dimonfah::dimonfah(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->position = position;
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);
	

	row = 0;
	hitbox.setSize(sf::Vector2f(50.0f, 20.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(0.f);
	
	hitbox.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + 35));
}

dimonfah::~dimonfah()
{
}

void dimonfah::Update(float deltaTime, Player player)
{
	animation.Updatewater(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void dimonfah::draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}
void dimonfah::re()
{
	body.setPosition(position);
	hitbox.setPosition(position);
}
sf::RectangleShape dimonfah::getBody() {
	return this->body;
}

void dimonfah::pickup()
{
	this->body.setPosition(-50.f, this->body.getPosition().y);
	this->hitbox.setPosition(-50.f, this->body.getPosition().y);
}
