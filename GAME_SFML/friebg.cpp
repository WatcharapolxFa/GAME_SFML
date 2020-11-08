#include "friebg.h"
#include "Animation.h"

#include <math.h>
friebg::friebg(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{	
	body.setSize(size);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getSize().x / 2.0f, body.getSize().y / 2.0f);

	row = 0;
}

friebg::~friebg()
{
}

void friebg::Update(float deltaTime,Player player)
{
	animation.Updatefrie(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}

void friebg::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

