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
	body.setOutlineThickness(1.f);
	body.setOutlineColor(sf::Color::Red);
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
}

sf::RectangleShape button::getBody() {
	return this->body;
}

