#include "boxsx.h"
#include "Animation.h"

#include <math.h>
boxsx::boxsx(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);


	row = 0;
	hitbox.setSize(sf::Vector2f(50.0f, 50.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + 20));
}

boxsx::~boxsx()
{
}

void boxsx::Update(float deltaTime, Player player)
{
	animation.Updatewater(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void boxsx::draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}
sf::RectangleShape boxsx::getBody() {
	return this->body;
}

