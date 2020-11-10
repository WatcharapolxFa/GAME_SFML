#include "box.h"
#include "Animation.h"

#include <math.h>
box::box(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime),
	body(texture, size, position)
{
	//body = new Platform(texture, size, position);

	row = 0;
}

box::~box()
{
}

void box::Update(float deltaTime, Player player)
{
	animation.Updatefrie(row, deltaTime);
	this->body.setBody(animation.uvRect);
}

void box::draw(sf::RenderWindow& window)
{
	this->body.Draw(window);
}

sf::RectangleShape box::getBody() {
	return this->body.getBody();
}

