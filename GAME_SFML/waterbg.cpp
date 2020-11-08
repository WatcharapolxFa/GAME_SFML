#include "waterbg.h"
#include "Animation.h"

#include <math.h>
waterbg::waterbg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{	
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	row = 0;
}

waterbg::~waterbg()
{
}

void waterbg::Update(float deltaTime, Player player)
{
	animation.Updatewater(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void waterbg::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

