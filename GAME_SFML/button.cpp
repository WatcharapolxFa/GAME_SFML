#include "button.h"
#include "Animation.h"

#include <math.h>
button::button(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	row = 0;
	row = 0;
	hitbox.setSize(sf::Vector2f(50.0f, 20.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOutlineColor(sf::Color::Yellow);
	hitbox.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + 40));
	
}

button::~button()
{
}

void button::Update(float deltaTime, Player player)
{
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void button::draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(hitbox);
}

sf::RectangleShape button::getBody() {
	return this->body;
}

